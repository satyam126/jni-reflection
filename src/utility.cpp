#include <sstream>
#include <c++/4.8.3/iostream>

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

void throwMethodNotFoundError(JNIEnv *env, const std::string &className, const std::string &methodName) {
    std::stringstream ss;
    ss << "Target method " << className.data() << "#" << methodName.data() << " was not found";
    throwError(env, "com/jnireflection/bindings/errors/MethodNotFoundError", ss.str());
}

void throwMethodSignatureError(JNIEnv *env, const std::string &errorMessage) {
    throwError(env, "com/jnireflection/bindings/errors/MethodSignatureError", errorMessage);
}

void throwConstructorNotFoundError(JNIEnv *env, const std::string &className, const std::string &constructorName) {
    std::stringstream ss;
    ss << "Target Constructor " << className.data() << "#" << constructorName.data() << " was not found";
    throwError(env, "com/jnireflection/bindings/errors/ConstructorNotFoundError", ss.str());
}

std::string jStringToString(JNIEnv *env, jstring jStr) {
    if (jStr == nullptr) {
        throwError(env, "java/lang/NullPointerException", "jstring is null");
        return "";
    }

    return env->GetStringUTFChars(jStr, JNI_FALSE);
}

bool jStringToString(JNIEnv *env, jstring inJStr, char * outStr, unsigned long strLength) {
    if (inJStr == nullptr) {
        throwError(env, "java/lang/NullPointerException", "jstring is null");
        return false;
    }

    env->GetStringUTFRegion(inJStr, 0, strLength, outStr);
    return true;
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

    if (instance == nullptr) {
        throwError(env, "java/lang/NullPointerException", "instance is null");
        return false;
    }

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

bool getStaticMethodId(JNIEnv *env, jstring jClassName, jstring jMethodName, jstring jSignature, jmethodID *methodId,
                      jclass *targetClass) {
    std::string className = jStringToString(env, jClassName);
    std::string methodName = jStringToString(env, jMethodName);
    std::string signature = jStringToString(env, jSignature);

    *targetClass = env->FindClass(className.data());
    if (*targetClass == nullptr) {
        throwClassNotFoundError(env, className);
        return false;
    }
    *methodId = env->GetStaticMethodID(*targetClass, methodName.data(), signature.data());
    if (*methodId == nullptr) {
        throwMethodNotFoundError(env, className, methodName);
        return false;
    }

    return true;
}

bool getInstanceMethodId(JNIEnv *env, jobject instance, jstring jMethodName, jstring jSignature, jmethodID *methodId) {
    if (instance == nullptr) {
        throwError(env, "java/lang/NullPointerException", "instance is null");
        return false;
    }

    std::string methodName = jStringToString(env, jMethodName);
    std::string signature = jStringToString(env, jSignature);

    jclass targetClass = env->GetObjectClass(instance);
    if (targetClass == nullptr) {
        throwClassNotFoundError(env, "null");
        return false;
    }
    *methodId = env->GetMethodID(targetClass, methodName.data(), signature.data());
    if (*methodId == nullptr) {
        throwMethodNotFoundError(env, "null", methodName);
        return false;
    }

    return true;
}

jint getIntValue(JNIEnv *env, jobject object) {
    jclass targetClass = env->GetObjectClass(object);
    jmethodID methodId = env->GetMethodID(targetClass, "intValue", "()I");
    if (methodId == nullptr) {
        throwMethodSignatureError(env, "could not convert argument to int");
        return 0;
    }
    return env->CallIntMethod(object, methodId);
}

jbyte getByteValue(JNIEnv *env, jobject object) {
    jclass targetClass = env->GetObjectClass(object);
    jmethodID methodId = env->GetMethodID(targetClass, "byteValue", "()B");
    if (methodId == nullptr) {
        throwMethodSignatureError(env, "could not convert argument to byte");
        return 0;
    }
    return env->CallByteMethod(object, methodId);
}

jchar getCharValue(JNIEnv *env, jobject object) {
    jclass targetClass = env->GetObjectClass(object);
    jmethodID methodId = env->GetMethodID(targetClass, "charValue", "()C");
    if (methodId == nullptr) {
        throwMethodSignatureError(env, "could not convert argument to char");
        return 0;
    }
    return env->CallCharMethod(object, methodId);
}

jdouble getDoubleValue(JNIEnv *env, jobject object) {
    jclass targetClass = env->GetObjectClass(object);
    jmethodID methodId = env->GetMethodID(targetClass, "doubleValue", "()D");
    if (methodId == nullptr) {
        throwMethodSignatureError(env, "could not convert argument to double");
        return 0;
    }
    return env->CallDoubleMethod(object, methodId);
}

jfloat getFloatValue(JNIEnv *env, jobject object) {
    jclass targetClass = env->GetObjectClass(object);
    jmethodID methodId = env->GetMethodID(targetClass, "floatValue", "()F");
    if (methodId == nullptr) {
        throwMethodSignatureError(env, "could not convert argument to float");
        return 0;
    }
    return env->CallFloatMethod(object, methodId);
}

jlong getLongValue(JNIEnv *env, jobject object) {
    jclass targetClass = env->GetObjectClass(object);
    jmethodID methodId = env->GetMethodID(targetClass, "longValue", "()J");
    if (methodId == nullptr) {
        throwMethodSignatureError(env, "could not convert argument to long");
        return 0;
    }
    return env->CallLongMethod(object, methodId);
}

jshort getShortValue(JNIEnv *env, jobject object) {
    jclass targetClass = env->GetObjectClass(object);
    jmethodID methodId = env->GetMethodID(targetClass, "shortValue", "()S");
    if (methodId == nullptr) {
        throwMethodSignatureError(env, "could not convert argument to short");
        return 0;
    }
    return env->CallShortMethod(object, methodId);
}

jboolean getBooleanValue(JNIEnv *env, jobject object) {
    jclass targetClass = env->GetObjectClass(object);
    jmethodID methodId = env->GetMethodID(targetClass, "booleanValue", "()Z");
    if (methodId == nullptr) {
        throwMethodSignatureError(env, "could not convert argument to boolean");
        return 0;
    }
    return env->CallBooleanMethod(object, methodId);
}

bool jObjectToJValue(JNIEnv *env, char typeChar, jobject object, jvalue *value) {
    switch (typeChar) {
        case 'L':
            value->l = object;
            break;
        case 'B':
            value->b = getByteValue(env, object);
            break;
        case 'C':
            value->c = getCharValue(env, object);
            break;
        case 'D':
            value->d = getDoubleValue(env, object);
            break;
        case 'F':
            value->f = getFloatValue(env, object);
            break;
        case 'I':
            value->i = getIntValue(env, object);
            break;
        case 'J':
            value->j = getLongValue(env, object);
            break;
        case 'S':
            value->s = getShortValue(env, object);
            break;
        case 'Z':
            value->z = getBooleanValue(env, object);
            break;
        default:
            std::string errorMessage = "invalid parameter type: ";
            errorMessage += typeChar;
            throwMethodSignatureError(env, errorMessage);
            return false;
    }
    return true;
}

bool jObjectArrayToJValuePtr
        (JNIEnv *env, jobjectArray arguments, std::string &parameterTypes, jvalue *jValues) {

    for (unsigned long i = 0; i < parameterTypes.length(); i++) {
        jobject argument = env->GetObjectArrayElement(arguments, i);
        char parameterType = parameterTypes.at(i);
        if (!jObjectToJValue(env, parameterType, argument, jValues + i)) {
            return false;
        }
    }

    return true;
}

bool getStaticMethodInvocationDetails
        (JNIEnv *env, jstring jClassName, jstring jMethodName, jstring jSignature, jobjectArray args,
         std::string &parameterTypes, jclass *targetClass, jmethodID *methodId, jvalue *jValues) {

    if (getStaticMethodId(env, jClassName, jMethodName, jSignature, methodId, targetClass)) {
        if (jObjectArrayToJValuePtr(env, args, parameterTypes, jValues)) {
            return true;
        }
    }

    return false;
}