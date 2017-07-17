#include <node.h>

namespace demo {

	using v8;

	void Method( const FunctionalCallbackInfo<Value>& args)
	{
		Isolate* isolate = args.GetIsolate();
		args.GetReturnValue().Set(String::NewFromUtf8(isolate,"world !"));
	}

	void init(Local<Object> exports) {
		NODE_SET_METHOD(exports, "hello_func", Method);
	}

	NODE_MODULE(addon, init);
}