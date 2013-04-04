#include <v8.h>
#include <node.h>
#include <pHash.h>

using namespace node;
using namespace v8;

const char* ToCString(const String::Utf8Value& value) {
    return *value ? *value : "<string conversion failed>";
}

static Handle<Value> imagehash(const Arguments& args) {
    String::Utf8Value str(args[0]);
    const char* file = ToCString(str);
    ulong64 hash = 0;
    ph_dct_imagehash(file, hash);
    return Number::New(hash);
}

void init(Handle<Object> target) {
    NODE_SET_METHOD(target, "imagehash", imagehash);
}

NODE_MODULE(pHash, init);
