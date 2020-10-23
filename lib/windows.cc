#include <node.h>
#include <windows.h>

namespace mousemanager {
    // v8 classes
    using v8::Exception;
    using v8::FunctionCallbackInfo;
    using v8::Isolate;
    using v8::Local;
    using v8::Object;
    using v8::String;
    using v8::Integer;
    using v8::Value;
    using v8::Number;

    void moveMouse(const FunctionCallbackInfo<Value>& args) {
        Isolate* isolate = args.GetIsolate();

        if (args.Length() < 2) {
            isolate->ThrowException(Exception::TypeError(
                String::NewFromUtf8(isolate, "Wrong Number of arguments").ToLocalChecked()
            ));

            return;
        }

        if (!args[0]->IsNumber() || !args[1]->IsNumber()) {
            isolate->ThrowException(Exception::TypeError(
                String::NewFromUtf8(isolate, "Wrong argument types").ToLocalChecked()
            ));

            return;
        }

        const int x = (int) args[0].As<Number>()->Value();
        const int y = (int) args[1].As<Number>()->Value();

        SetCursorPos(x, y);
    }

    void init(Local<Object> exports) {
        NODE_SET_METHOD(exports, "moveMouse", moveMouse);
    }

    NODE_MODULE(NODE_GYP_MODULE_NAME, init);
}