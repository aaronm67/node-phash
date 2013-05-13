#include <v8.h>
#include <node.h>
#include <pHash.h>
#include <sstream>
#include <cstdio>

using namespace node;
using namespace v8;

const char* ToCString(const String::Utf8Value& value) {
    return *value ? *value : "<string conversion failed>";
}

template <typename T>
    string NumberToString ( T Number )
    {
        ostringstream ss;
        ss << Number;
        return ss.str();
    }

template <typename T>
    T StringToNumber ( const string &Text )
    {
        istringstream ss(Text);
        T result;
        return ss >> result ? result : 0;
    }


Handle<Value> ImageHash(const Arguments& args) {
    HandleScope scope;
    string result;

    try {
        String::Utf8Value str(args[0]);
        const char* file = ToCString(str);
        ulong64 hash = 0;
        ph_dct_imagehash(file, hash);
        result  = NumberToString(hash);
    } catch(...) {
        // something went wrong with hashing
        // probably a CImg or ImageMagick IO Problem
        // return -1
        result = "-1";
    }

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
  NODE_SET_METHOD(target, "imagehash", ImageHash);
  NODE_SET_METHOD(target, "imageHash", ImageHash);
  NODE_SET_METHOD(target,"hammingDistance",HammingDistance);
  NODE_SET_METHOD(target, "oldHash", oldHash);
}

NODE_MODULE(pHash, RegisterModule);
