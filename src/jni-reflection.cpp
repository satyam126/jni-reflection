#define DEBUG


#include <iostream>
#include <sstream>

#include "utility.h"
#include "jni-reflection.h"


JNIEXPORT jobject JNICALL Java_com_jnireflection_bindings_JNIReflection_getStaticObject
        (JNIEnv *env, jclass clazz, jstring jClassName, jstring jFieldName, jstring jSignature) {
    std::string className = jStringToString(env, jClassName);
    std::string fieldName = jStringToString(env, jFieldName);
    std::string signature = jStringToString(env, jSignature);

    jclass targetClass = env->FindClass(className.data());
#ifdef DEBUG
    if (targetClass == nullptr) {
        throwClassNotFoundError(env, className);
        return nullptr;
    }
#endif

    jfieldID fieldId = env->GetStaticFieldID(targetClass, fieldName.data(), signature.data());
#ifdef DEBUG
    if (fieldId == nullptr) {
        throwFieldNotFoundError(env, className, fieldName);
        return nullptr;
    }
#endif

    env->DeleteLocalRef(targetClass);

    return env->GetStaticObjectField(targetClass, fieldId);
}

void
Java_com_jnireflection_bindings_JNIReflection_setStaticObject(JNIEnv *env, jclass clazz, jobject object,
                                                              jstring jClassName, jstring jFieldName,
                                                              jstring jSignature) {
    std::string className = jStringToString(env, jClassName);
    std::string fieldName = jStringToString(env, jFieldName);
    std::string signature = jStringToString(env, jSignature);

    jclass targetClass = env->FindClass(className.data());
#ifdef DEBUG
    if (targetClass == nullptr) {
        throwClassNotFoundError(env, className);
        return;
    }
#endif

    jfieldID fieldId = env->GetStaticFieldID(targetClass, fieldName.data(), signature.data());
#ifdef DEBUG
    if (fieldId == nullptr) {
        throwFieldNotFoundError(env, className, fieldName);
        return;
    }
#endif

    env->SetStaticObjectField(targetClass, fieldId, object);
}

JNIEXPORT jobjectArray JNICALL Java_com_jnireflection_bindings_JNIReflection_getInstances
        (JNIEnv *env, jclass clazz, jstring jTargetClass) {
    if (jvmti == nullptr) {
        initialize(env);
    }

    std::string targetClassString = jStringToString(env, jTargetClass);
    jclass targetClass = env->FindClass(targetClassString.data());

    jvmtiError status = jvmti->IterateOverInstancesOfClass(
            targetClass, JVMTI_HEAP_OBJECT_EITHER, heapObjectCallback, nullptr
    );
    if (status != JVMTI_ERROR_NONE) {
        throwError(env, "IterateOverInstancesOfClass");
        return nullptr;
    }

    jlong tag = 1;
    jint count;
    jobject *instances;
    status = jvmti->GetObjectsWithTags(1, &tag, &count, &instances, nullptr);
    if (status != JVMTI_ERROR_NONE) {
        throwError(env, "GetObjectsWithTags");
        return nullptr;
    }

    jobjectArray instancesArray = env->NewObjectArray(count, targetClass, nullptr);
    for (int i = 0; i < count; i++) {
        jobject currentInstance = instances[i];
        jvmti->SetTag(currentInstance, 0);
        env->SetObjectArrayElement(instancesArray, i, currentInstance);
    }

    jvmti->Deallocate((unsigned char *) instances);
    env->DeleteLocalRef(targetClass);

    return instancesArray;
}