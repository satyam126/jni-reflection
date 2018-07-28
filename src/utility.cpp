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
    jclass stringClass = env->GetObjectClass(jStr);
    jmethodID getBytesId = env->GetMethodID(stringClass, "getBytes", "(Ljava/lang/String;)[B");
    jbyteArray stringJBytes = (jbyteArray) env->CallObjectMethod(jStr, getBytesId, env->NewStringUTF("UTF-8"));

    // get buffer details
    size_t length = (size_t) env->GetArrayLength(stringJBytes);
    jbyte *pBytes = env->GetByteArrayElements(stringJBytes, nullptr);

    // copy bytes over
    std::string ret = std::string((char *) pBytes, length);
    env->ReleaseByteArrayElements(stringJBytes, pBytes, JNI_ABORT);

    // release references
    env->DeleteLocalRef(stringJBytes);
    env->DeleteLocalRef(stringClass);

    return ret;
}

jvmtiIterationControl JNICALL
heapObjectCallback(jlong class_tag, jlong size, jlong *tag_ptr, void *user_data) {
    *tag_ptr = 1;
    return JVMTI_ITERATION_CONTINUE;
}

bool getStaticFieldId(JNIEnv *env, jstring jClassName, jstring jFieldName, jstring jSignature, jfieldID *fieldId,
                      jclass *targetClass) {
    std::string className = jStringToString(env, jClassName);
    std::string fieldName = jStringToString(env, jFieldName);
    std::string signature = jStringToString(env, jSignature);

    *targetClass = env->FindClass(className.data());
    if (*targetClass == nullptr) {
        throwClassNotFoundError(env, className);
        return false;
    }
    *fieldId = env->GetStaticFieldID(*targetClass, fieldName.data(), signature.data());
    if (*fieldId == nullptr) {
        throwFieldNotFoundError(env, className, fieldName);
        return false;
    }

    return true;
}

bool getInstanceFieldId(JNIEnv *env, jobject instance, jstring jFieldName, jstring jSignature, jfieldID *fieldId) {
    std::string fieldName = jStringToString(env, jFieldName);
    std::string signature = jStringToString(env, jSignature);

    jclass targetClass = env->GetObjectClass(instance);
    if (targetClass == nullptr) {
        throwClassNotFoundError(env, "null");
        return false;
    }

    *fieldId = env->GetFieldID(targetClass, fieldName.data(), signature.data());
    if (*fieldId == nullptr) {
        throwFieldNotFoundError(env, "null", fieldName);
        return false;
    }

    return true;
}