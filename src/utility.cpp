#include <sstream>

#include "utility.h"


jvmtiEnv *jvmti;


void initialize(JNIEnv *env) {
    JavaVM *vm;
    env->GetJavaVM(&vm);

    vm->GetEnv((void **) &jvmti, JVMTI_VERSION_1_0);

    jvmtiCapabilities capabilities = {0};
    capabilities.can_tag_objects = 1;
    jvmti->AddCapabilities(&capabilities);
}

void throwError(JNIEnv *env, const std::string &message) {
    throwError(env, "java/lang/Error", message);
}

void throwError(JNIEnv *env, const std::string &errorClassName, const std::string &message) {
    jclass errorClass = env->FindClass(errorClassName.data());
    env->ThrowNew(errorClass, message.data());
}

void throwClassNotFoundError(JNIEnv *env, const std::string &className) {
    std::stringstream ss;
    ss << "Target class " << className.data() << " was not found";
    throwError(env, "com/jnireflection/bindings/errors/ClassNotFoundError", ss.str());
}

void throwFieldNotFoundError(JNIEnv *env, const std::string &className, const std::string &fieldName) {
    std::stringstream ss;
    ss << "Target field " << className.data() << "#" << fieldName.data() << " was not found";
    throwError(env, "com/jnireflection/bindings/errors/FieldNotFoundError", ss.str());
}

void throwMethodNotFoundError(JNIEnv *env, const std::string &className, const std::string &fieldName) {
    std::stringstream ss;
    ss << "Target method " << className.data() << "#" << fieldName.data() << " was not found";
    throwError(env, "com/jnireflection/bindings/errors/MethodNotFoundError", ss.str());
}

void throwConstructorNotFoundError(JNIEnv *env, const std::string &className, const std::string &fieldName) {
    std::stringstream ss;
    ss << "Target Constructor " << className.data() << "#" << fieldName.data() << " was not found";
    throwError(env, "com/jnireflection/bindings/errors/ConstructorNotFoundError", ss.str());
}

std::string jStringToString(JNIEnv *env, jstring jStr) {
    if (jStr == nullptr) {
        return "";
    }

    // get string bytes
    const jclass stringClass = env->GetObjectClass(jStr);
    const jmethodID getBytesId = env->GetMethodID(stringClass, "getBytes", "(Ljava/lang/String;)[B");
    const jbyteArray stringJbytes = (jbyteArray) env->CallObjectMethod(jStr, getBytesId, env->NewStringUTF("UTF-8"));

    // get buffer details
    size_t length = (size_t) env->GetArrayLength(stringJbytes);
    jbyte *pBytes = env->GetByteArrayElements(stringJbytes, nullptr);

    // copy bytes over
    std::string ret = std::string((char *) pBytes, length);
    env->ReleaseByteArrayElements(stringJbytes, pBytes, JNI_ABORT);

    // release references
    env->DeleteLocalRef(stringJbytes);
    env->DeleteLocalRef(stringClass);

    return ret;
}

jvmtiIterationControl JNICALL
heapObjectCallback(jlong class_tag, jlong size, jlong *tag_ptr, void *user_data) {
    *tag_ptr = 1;
    return JVMTI_ITERATION_CONTINUE;
}