#include <v8.h>
#include <node.h>
#include <pHash.h>

using namespace node;
using namespace v8;



const char* ToCString(const String::Utf8Value& value) {
    return *value ? *value : "<string conversion failed>";
}

Handle<Value> ImageHash(const Arguments& args) {
  try {
    String::Utf8Value str(args[0]);
    const char* file = ToCString(str);
    ulong64 hash = 0;
    ph_dct_imagehash(file, hash);
    return Number::New(hash);
  } catch(...) {
    return Number::New(-1);
  }
}

Handle<Value> HammingDistance(const Arguments& args) {
    HandleScope scope;
    uint32_t hasha = args[0]->ToUint32()->Value();
	uint32_t hashb = args[1]->ToUint32()->Value();
	int distance = ph_hamming_distance(hasha, hashb);
	
    return scope.Close(Integer::New(distance));
}


void RegisterModule(Handle<Object> target) {
  NODE_SET_METHOD(target, "imagehash", ImageHash);
  NODE_SET_METHOD(target, "imageHash", ImageHash);
  NODE_SET_METHOD(target,"hammingDistance",HammingDistance);
}

/*
void init(Handle<Object> target) {
    NODE_SET_METHOD(target, "imagehash", imagehash);
}
*/
NODE_MODULE(pHash, RegisterModule);
