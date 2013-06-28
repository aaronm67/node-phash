#include <v8.h>
#include <node.h>
#include <pHash.h>
#include <sstream>
#include <cstdio>
using namespace node;
using namespace v8;

struct PhashRequest {
    string file;
    string hash;
    uv_work_t request;
    Persistent<Function> callback;
};

template <typename T>
string NumberToString ( T Number ) {
    ostringstream ss;
    ss << Number;
    return ss.str();
}

template <typename T>
T StringToNumber ( const string &Text ) {
    istringstream ss(Text);
    T result;
    return ss >> result ? result : 0;
}

const char* ToCString(const String::Utf8Value& value) {
    return *value ? *value : "<string conversion failed>";
}

const string getHash(const char* file) {
    string ret;
    try {
        ulong64 hash = 0;
        ph_dct_imagehash(file, hash);
        return NumberToString(hash);   
    }
    catch(...) {
        // something went wrong with hashing
        // probably a CImg or ImageMagick IO Problem
        return "0";
    }
}

void HashWorker(uv_work_t* req) {
    PhashRequest* request = static_cast<PhashRequest*>(req->data);
    request->hash = getHash(request->file.c_str());
}

void HashAfter(uv_work_t* req, int status) {
    HandleScope scope;
    PhashRequest* request = static_cast<PhashRequest*>(req->data);

    Handle<Value> argv[2];

    if (request->hash == "0") {
        argv[0] = String::New("Error getting image hash");
    }
    else {
        argv[0] = Undefined();
    }

    argv[1] = String::New(request->hash.c_str());
    request->callback->Call(Context::GetCurrent()->Global(), 2, argv);
    request->callback.Dispose();

    delete request;
}

Handle<Value> ImageHashAsync(const Arguments& args) {
    if (args.Length() < 2 || !args[1]->IsFunction()) {
        // no callback defined
        return ThrowException(Exception::Error(String::New("Callback is required and must be an Function.")));
    }

    String::Utf8Value str(args[0]);
    Handle<Function> cb = Handle<Function>::Cast(args[1]);
    
    PhashRequest* request = new PhashRequest;
    request->callback = Persistent<Function>::New(cb);
    request->file = string(*str);
    request->request.data = request;
    uv_queue_work(uv_default_loop(), &request->request, HashWorker, HashAfter);
    return Undefined();
}

Handle<Value> ImageHashSync(const Arguments& args) {
    HandleScope scope;
    String::Utf8Value str(args[0]);
    string result = getHash(*str);
    return scope.Close(String::New(result.c_str()));
}

Handle<Value> HammingDistance(const Arguments& args) {
    HandleScope scope;

    String::Utf8Value arg0(args[0]);
    String::Utf8Value arg1(args[1]);
    string aString = string(ToCString(arg0));
    string bString = string(ToCString(arg1));
    
    ulong64 hasha = StringToNumber<ulong64>(aString);
    ulong64 hashb = StringToNumber<ulong64>(bString);
    
    int distance = ph_hamming_distance(hasha,hashb);
    
    return scope.Close(Number::New(distance));
}

/*
    See https://github.com/aaronm67/node-phash/issues/4
    V8 only supports 32 bit integers, so hashes must be returned as strings.
    This is a legacy version that returns a 32 bit integer of the hash.
*/
Handle<Value> oldHash(const Arguments& args) {
    String::Utf8Value str(args[0]);
    const char* file = ToCString(str);
    ulong64 hash = 0;
    ph_dct_imagehash(file, hash);
    return Number::New(hash);
}

void RegisterModule(Handle<Object> target) {
  NODE_SET_METHOD(target, "imageHashSync", ImageHashSync);
  NODE_SET_METHOD(target, "imageHash", ImageHashAsync);
  NODE_SET_METHOD(target, "hammingDistance", HammingDistance);
 
  // methods below are deprecated
  NODE_SET_METHOD(target, "oldHash", oldHash);
  NODE_SET_METHOD(target, "imagehash", ImageHashSync);
}

NODE_MODULE(pHash, RegisterModule);
