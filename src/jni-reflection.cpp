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

JNIEXPORT void JNICALL Java_com_jnireflection_bindings_JNIReflection_setStaticObject
        (JNIEnv *env, jclass clazz, jobject newObject, jstring jClassName, jstring jFieldName, jstring jSignature) {
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

JNIEXPORT jshort JNICALL Java_com_jnireflection_bindings_JNIReflection_getStaticShort
        (JNIEnv *env, jclass clazz, jstring jClassName, jstring jFieldName, jstring jSignature) {
    jfieldID fieldId;
    jclass targetClass;
    if (getStaticFieldId(env, jClassName, jFieldName, jSignature, &fieldId, &targetClass)) {
        return env->GetStaticShortField(targetClass, fieldId);
    }
    return 0;
}

JNIEXPORT void JNICALL Java_com_jnireflection_bindings_JNIReflection_setStaticShort
        (JNIEnv *env, jclass clazz, jshort newShort, jstring jClassName, jstring jFieldName, jstring jSignature) {
    jfieldID fieldId;
    jclass targetClass;
    if (getStaticFieldId(env, jClassName, jFieldName, jSignature, &fieldId, &targetClass)) {
        env->SetStaticShortField(targetClass, fieldId, newShort);
    }
}

JNIEXPORT jint JNICALL Java_com_jnireflection_bindings_JNIReflection_getStaticInt
        (JNIEnv *env, jclass clazz, jstring jClassName, jstring jFieldName, jstring jSignature) {
    jfieldID fieldId;
    jclass targetClass;
    if (getStaticFieldId(env, jClassName, jFieldName, jSignature, &fieldId, &targetClass)) {
        return env->GetStaticIntField(targetClass, fieldId);
    }
    return 0;
}

JNIEXPORT void JNICALL Java_com_jnireflection_bindings_JNIReflection_setStaticInt
        (JNIEnv *env, jclass clazz, jint newInt, jstring jClassName, jstring jFieldName, jstring jSignature) {
    jfieldID fieldId;
    jclass targetClass;
    if (getStaticFieldId(env, jClassName, jFieldName, jSignature, &fieldId, &targetClass)) {
        env->SetStaticIntField(targetClass, fieldId, newInt);
    }
}

JNIEXPORT jlong JNICALL Java_com_jnireflection_bindings_JNIReflection_getStaticLong
        (JNIEnv *env, jclass clazz, jstring jClassName, jstring jFieldName, jstring jSignature) {
    jfieldID fieldId;
    jclass targetClass;
    if (getStaticFieldId(env, jClassName, jFieldName, jSignature, &fieldId, &targetClass)) {
        return env->GetStaticLongField(targetClass, fieldId);
    }
    return 0;
}

JNIEXPORT void JNICALL Java_com_jnireflection_bindings_JNIReflection_setStaticLong
        (JNIEnv *env, jclass clazz, jlong newLong, jstring jClassName, jstring jFieldName, jstring jSignature) {
    jfieldID fieldId;
    jclass targetClass;
    if (getStaticFieldId(env, jClassName, jFieldName, jSignature, &fieldId, &targetClass)) {
        env->SetStaticLongField(targetClass, fieldId, newLong);
    }
}

JNIEXPORT jfloat JNICALL Java_com_jnireflection_bindings_JNIReflection_getStaticFloat
        (JNIEnv *env, jclass clazz, jstring jClassName, jstring jFieldName, jstring jSignature) {
    jfieldID fieldId;
    jclass targetClass;
    if (getStaticFieldId(env, jClassName, jFieldName, jSignature, &fieldId, &targetClass)) {
        return env->GetStaticFloatField(targetClass, fieldId);
    }
    return 0.0f;
}

JNIEXPORT void JNICALL Java_com_jnireflection_bindings_JNIReflection_setStaticFloat
        (JNIEnv *env, jclass clazz, jfloat newFloat, jstring jClassName, jstring jFieldName, jstring jSignature) {
    jfieldID fieldId;
    jclass targetClass;
    if (getStaticFieldId(env, jClassName, jFieldName, jSignature, &fieldId, &targetClass)) {
        env->SetStaticFloatField(targetClass, fieldId, newFloat);
    }
}

JNIEXPORT jdouble JNICALL Java_com_jnireflection_bindings_JNIReflection_getStaticDouble
        (JNIEnv *env, jclass clazz, jstring jClassName, jstring jFieldName, jstring jSignature){
    jfieldID fieldId;
    jclass targetClass;
    if (getStaticFieldId(env, jClassName, jFieldName, jSignature, &fieldId, &targetClass)) {
        return env->GetStaticDoubleField(targetClass, fieldId);
    }
    return 0.0;
}

JNIEXPORT void JNICALL Java_com_jnireflection_bindings_JNIReflection_setStaticDouble
        (JNIEnv *env, jclass clazz, jdouble newDouble, jstring jClassName, jstring jFieldName, jstring jSignature) {
    jfieldID fieldId;
    jclass targetClass;
    if (getStaticFieldId(env, jClassName, jFieldName, jSignature, &fieldId, &targetClass)) {
        env->SetStaticDoubleField(targetClass, fieldId, newDouble);
    }
}

JNIEXPORT jboolean JNICALL Java_com_jnireflection_bindings_JNIReflection_getStaticBoolean
        (JNIEnv *env, jclass clazz, jstring jClassName, jstring jFieldName, jstring jSignature){
    jfieldID fieldId;
    jclass targetClass;
    if (getStaticFieldId(env, jClassName, jFieldName, jSignature, &fieldId, &targetClass)) {
        return env->GetStaticBooleanField(targetClass, fieldId);
    }
    return JNI_FALSE;
}

JNIEXPORT void JNICALL Java_com_jnireflection_bindings_JNIReflection_setStaticBoolean
        (JNIEnv *env, jclass clazz, jboolean newBoolean, jstring jClassName, jstring jFieldName, jstring jSignature) {
    jfieldID fieldId;
    jclass targetClass;
    if (getStaticFieldId(env, jClassName, jFieldName, jSignature, &fieldId, &targetClass)) {
        env->SetStaticBooleanField(targetClass, fieldId, newBoolean);
    }
}

JNIEXPORT jchar JNICALL Java_com_jnireflection_bindings_JNIReflection_getStaticChar
        (JNIEnv *env, jclass clazz, jstring jClassName, jstring jFieldName, jstring jSignature){
    jfieldID fieldId;
    jclass targetClass;
    if (getStaticFieldId(env, jClassName, jFieldName, jSignature, &fieldId, &targetClass)) {
        return env->GetStaticCharField(targetClass, fieldId);
    }
    return 0;
}

JNIEXPORT void JNICALL Java_com_jnireflection_bindings_JNIReflection_setStaticChar
        (JNIEnv *env, jclass clazz, jchar newChar, jstring jClassName, jstring jFieldName, jstring jSignature) {
    jfieldID fieldId;
    jclass targetClass;
    if (getStaticFieldId(env, jClassName, jFieldName, jSignature, &fieldId, &targetClass)) {
        env->SetStaticCharField(targetClass, fieldId, newChar);
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