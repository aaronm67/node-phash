/*
 *  Copyright (c) 2013 Aaron Marasco. All rights reserved.
 * 
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 * 
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
 * LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 * OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
 * WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include <v8.h>
#include <node.h>
#include <nan.h>
#include "../deps/pHash/pHash.h"
#include <sstream>
#include <fstream>
#include <cstdio>

using namespace node;
using namespace v8;

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

const char* toCString(const String::Utf8Value& value) {
    return *value ? *value : "<string conversion failed>";
}

bool fileExists(const char* filename) {
    ifstream file(filename);
    return file.good();
}

const string getHash(const char* file) {
    // prevent segfault on an empty file, see https://github.com/aaronm67/node-phash/issues/8
    if (!fileExists(file)) {
        return "0";
    }

    string ret;
    try {
        ulong64 hash = 0;
        ph_dct_imagehash(file, hash);
        return NumberToString(hash);
    }
    catch (...) {
        // something went wrong; probably a problem with CImg.
        return "0";
    }
}

class PhashRequest : public Nan::AsyncWorker {
  public:
    PhashRequest(Nan::Callback *callback, string file)
      : AsyncWorker(callback), file(file) {}
    ~PhashRequest() {}

    void Execute () {
        hash = getHash(file.c_str());
    }

    void HandleOKCallback () {
        Nan::HandleScope scope;

        Local<Value> argv[] = {
            Nan::Undefined(),
            Nan::New(hash.c_str()).ToLocalChecked()
        };

        if (hash == "0") {
            argv[0] = Nan::Error("Error getting image hash");
        }

        callback->Call(2, argv);
    }

    string file;
    string hash;
};


NAN_METHOD(ImageHashAsync) {
  if (info.Length() < 2 || !info[1]->IsFunction()) {
    Nan::ThrowError("Callback is required and must be an Function.");
  }

  String::Utf8Value file_arg(info[0]);
  string file = string(toCString(file_arg));

  Nan::Callback *callback = new Nan::Callback(info[1].As<Function>());

  Nan::AsyncQueueWorker(new PhashRequest(callback, file));
}

void ImageHashSync(const Nan::FunctionCallbackInfo<v8::Value>& args) {
    Nan::HandleScope scope;
    String::Utf8Value str(args[0]);
    string result = getHash(*str);
    args.GetReturnValue().Set(Nan::New(result.c_str()).ToLocalChecked());
}

void HammingDistance(const Nan::FunctionCallbackInfo<v8::Value>& args) {
    Nan::HandleScope scope;

    String::Utf8Value arg0(args[0]);
    String::Utf8Value arg1(args[1]);
    string aString = string(toCString(arg0));
    string bString = string(toCString(arg1));

    ulong64 hasha = StringToNumber<ulong64>(aString);
    ulong64 hashb = StringToNumber<ulong64>(bString);

    int distance = ph_hamming_distance(hasha,hashb);

    args.GetReturnValue().Set(Nan::New<v8::Number>(distance));
}

/*
    See https://github.com/aaronm67/node-phash/issues/4
    V8 only supports 32 bit integers, so hashes must be returned as strings.
    This is a legacy version that returns a 32 bit integer of the hash.
*/
void oldHash(const Nan::FunctionCallbackInfo<v8::Value>& args) {
    Nan::HandleScope scope;

    String::Utf8Value str(args[0]);
    const char* file = toCString(str);
    ulong64 hash = 0;
    ph_dct_imagehash(file, hash);
    args.GetReturnValue().Set(Nan::New<v8::Number>(hash));
}

void RegisterModule(Handle<Object> target) {
    Nan::SetMethod(target, "imageHashSync", ImageHashSync);
    Nan::SetMethod(target, "imageHash", ImageHashAsync);
    Nan::SetMethod(target, "hammingDistance", HammingDistance);

    // methods below are deprecated
    Nan::SetMethod(target, "imagehash", ImageHashAsync);
    Nan::SetMethod(target, "oldHash", oldHash);
}

NODE_MODULE(pHashBinding, RegisterModule);
