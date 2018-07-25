#include <iostream>
#include <sstream>

#include "utility.h"
#include "jni-reflection.h"


JNIEXPORT jobject JNICALL Java_com_jnireflection_bindings_JNIReflection_getStaticObject
        (JNIEnv *env, jclass clazz, jstring jClassName, jstring jFieldName, jstring jSignature) {
    jfieldID fieldId;
    jclass targetClass;
    if (getStaticFieldId(env, jClassName, jFieldName, jSignature, &fieldId, &targetClass)) {
        return env->GetStaticObjectField(targetClass, fieldId);
    }
    return nullptr;
}

void
Java_com_jnireflection_bindings_JNIReflection_setStaticObject(JNIEnv *env, jclass clazz, jobject newObject,
                                                              jstring jClassName, jstring jFieldName,
                                                              jstring jSignature) {
    jfieldID fieldId;
    jclass targetClass;
    if (getStaticFieldId(env, jClassName, jFieldName, jSignature, &fieldId, &targetClass)) {
        env->SetStaticObjectField(targetClass, fieldId, newObject);
    }
}

JNIEXPORT jbyte JNICALL Java_com_jnireflection_bindings_JNIReflection_getStaticByte
        (JNIEnv *env, jclass clazz, jstring jClassName, jstring jFieldName, jstring jSignature) {
    jfieldID fieldId;
    jclass targetClass;
    if (getStaticFieldId(env, jClassName, jFieldName, jSignature, &fieldId, &targetClass)) {
        return env->GetStaticByteField(targetClass, fieldId);
    }
    return 0;
}

JNIEXPORT void JNICALL Java_com_jnireflection_bindings_JNIReflection_setStaticByte
        (JNIEnv *env, jclass clazz, jbyte newByte, jstring jClassName, jstring jFieldName, jstring jSignature) {
    jfieldID fieldId;
    jclass targetClass;
    if (getStaticFieldId(env, jClassName, jFieldName, jSignature, &fieldId, &targetClass)) {
        env->SetStaticByteField(targetClass, fieldId, newByte);
    }
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