#include <iostream>
#include <sstream>

#include "utility.h"
#include "jni-reflection.h"


JNIEXPORT jobject JNICALL Java_com_deimos_bindings_JniAccessor_getStaticObject
        (JNIEnv *env, jclass clazz, jstring jClassName, jstring jFieldName, jstring jSignature) {
    jfieldID fieldId;
    jclass targetClass;
    if (getStaticFieldId(env, jClassName, jFieldName, jSignature, &fieldId, &targetClass)) {
        return env->GetStaticObjectField(targetClass, fieldId);
    }
    return nullptr;
}

JNIEXPORT void JNICALL Java_com_deimos_bindings_JniAccessor_setStaticObject
        (JNIEnv *env, jclass clazz, jobject newObject, jstring jClassName, jstring jFieldName, jstring jSignature) {
    jfieldID fieldId;
    jclass targetClass;
    if (getStaticFieldId(env, jClassName, jFieldName, jSignature, &fieldId, &targetClass)) {
        env->SetStaticObjectField(targetClass, fieldId, newObject);
    }
}

JNIEXPORT jbyte JNICALL Java_com_deimos_bindings_JniAccessor_getStaticByte
        (JNIEnv *env, jclass clazz, jstring jClassName, jstring jFieldName, jstring jSignature) {
    jfieldID fieldId;
    jclass targetClass;
    if (getStaticFieldId(env, jClassName, jFieldName, jSignature, &fieldId, &targetClass)) {
        return env->GetStaticByteField(targetClass, fieldId);
    }
    return 0;
}

JNIEXPORT void JNICALL Java_com_deimos_bindings_JniAccessor_setStaticByte
        (JNIEnv *env, jclass clazz, jbyte newByte, jstring jClassName, jstring jFieldName, jstring jSignature) {
    jfieldID fieldId;
    jclass targetClass;
    if (getStaticFieldId(env, jClassName, jFieldName, jSignature, &fieldId, &targetClass)) {
        env->SetStaticByteField(targetClass, fieldId, newByte);
    }
}

JNIEXPORT jshort JNICALL Java_com_deimos_bindings_JniAccessor_getStaticShort
        (JNIEnv *env, jclass clazz, jstring jClassName, jstring jFieldName, jstring jSignature) {
    jfieldID fieldId;
    jclass targetClass;
    if (getStaticFieldId(env, jClassName, jFieldName, jSignature, &fieldId, &targetClass)) {
        return env->GetStaticShortField(targetClass, fieldId);
    }
    return 0;
}

JNIEXPORT void JNICALL Java_com_deimos_bindings_JniAccessor_setStaticShort
        (JNIEnv *env, jclass clazz, jshort newShort, jstring jClassName, jstring jFieldName, jstring jSignature) {
    jfieldID fieldId;
    jclass targetClass;
    if (getStaticFieldId(env, jClassName, jFieldName, jSignature, &fieldId, &targetClass)) {
        env->SetStaticShortField(targetClass, fieldId, newShort);
    }
}

JNIEXPORT jint JNICALL Java_com_deimos_bindings_JniAccessor_getStaticInt
        (JNIEnv *env, jclass clazz, jstring jClassName, jstring jFieldName, jstring jSignature) {
    jfieldID fieldId;
    jclass targetClass;
    if (getStaticFieldId(env, jClassName, jFieldName, jSignature, &fieldId, &targetClass)) {
        return env->GetStaticIntField(targetClass, fieldId);
    }
    return 0;
}

JNIEXPORT void JNICALL Java_com_deimos_bindings_JniAccessor_setStaticInt
        (JNIEnv *env, jclass clazz, jint newInt, jstring jClassName, jstring jFieldName, jstring jSignature) {
    jfieldID fieldId;
    jclass targetClass;
    if (getStaticFieldId(env, jClassName, jFieldName, jSignature, &fieldId, &targetClass)) {
        env->SetStaticIntField(targetClass, fieldId, newInt);
    }
}

JNIEXPORT jlong JNICALL Java_com_deimos_bindings_JniAccessor_getStaticLong
        (JNIEnv *env, jclass clazz, jstring jClassName, jstring jFieldName, jstring jSignature) {
    jfieldID fieldId;
    jclass targetClass;
    if (getStaticFieldId(env, jClassName, jFieldName, jSignature, &fieldId, &targetClass)) {
        return env->GetStaticLongField(targetClass, fieldId);
    }
    return 0;
}

JNIEXPORT void JNICALL Java_com_deimos_bindings_JniAccessor_setStaticLong
        (JNIEnv *env, jclass clazz, jlong newLong, jstring jClassName, jstring jFieldName, jstring jSignature) {
    jfieldID fieldId;
    jclass targetClass;
    if (getStaticFieldId(env, jClassName, jFieldName, jSignature, &fieldId, &targetClass)) {
        env->SetStaticLongField(targetClass, fieldId, newLong);
    }
}

JNIEXPORT jfloat JNICALL Java_com_deimos_bindings_JniAccessor_getStaticFloat
        (JNIEnv *env, jclass clazz, jstring jClassName, jstring jFieldName, jstring jSignature) {
    jfieldID fieldId;
    jclass targetClass;
    if (getStaticFieldId(env, jClassName, jFieldName, jSignature, &fieldId, &targetClass)) {
        return env->GetStaticFloatField(targetClass, fieldId);
    }
    return 0.0f;
}

JNIEXPORT void JNICALL Java_com_deimos_bindings_JniAccessor_setStaticFloat
        (JNIEnv *env, jclass clazz, jfloat newFloat, jstring jClassName, jstring jFieldName, jstring jSignature) {
    jfieldID fieldId;
    jclass targetClass;
    if (getStaticFieldId(env, jClassName, jFieldName, jSignature, &fieldId, &targetClass)) {
        env->SetStaticFloatField(targetClass, fieldId, newFloat);
    }
}

JNIEXPORT jdouble JNICALL Java_com_deimos_bindings_JniAccessor_getStaticDouble
        (JNIEnv *env, jclass clazz, jstring jClassName, jstring jFieldName, jstring jSignature) {
    jfieldID fieldId;
    jclass targetClass;
    if (getStaticFieldId(env, jClassName, jFieldName, jSignature, &fieldId, &targetClass)) {
        return env->GetStaticDoubleField(targetClass, fieldId);
    }
    return 0.0;
}

JNIEXPORT void JNICALL Java_com_deimos_bindings_JniAccessor_setStaticDouble
        (JNIEnv *env, jclass clazz, jdouble newDouble, jstring jClassName, jstring jFieldName, jstring jSignature) {
    jfieldID fieldId;
    jclass targetClass;
    if (getStaticFieldId(env, jClassName, jFieldName, jSignature, &fieldId, &targetClass)) {
        env->SetStaticDoubleField(targetClass, fieldId, newDouble);
    }
}

JNIEXPORT jboolean JNICALL Java_com_deimos_bindings_JniAccessor_getStaticBoolean
        (JNIEnv *env, jclass clazz, jstring jClassName, jstring jFieldName, jstring jSignature) {
    jfieldID fieldId;
    jclass targetClass;
    if (getStaticFieldId(env, jClassName, jFieldName, jSignature, &fieldId, &targetClass)) {
        return env->GetStaticBooleanField(targetClass, fieldId);
    }
    return JNI_FALSE;
}

JNIEXPORT void JNICALL Java_com_deimos_bindings_JniAccessor_setStaticBoolean
        (JNIEnv *env, jclass clazz, jboolean newBoolean, jstring jClassName, jstring jFieldName, jstring jSignature) {
    jfieldID fieldId;
    jclass targetClass;
    if (getStaticFieldId(env, jClassName, jFieldName, jSignature, &fieldId, &targetClass)) {
        env->SetStaticBooleanField(targetClass, fieldId, newBoolean);
    }
}

JNIEXPORT jchar JNICALL Java_com_deimos_bindings_JniAccessor_getStaticChar
        (JNIEnv *env, jclass clazz, jstring jClassName, jstring jFieldName, jstring jSignature) {
    jfieldID fieldId;
    jclass targetClass;
    if (getStaticFieldId(env, jClassName, jFieldName, jSignature, &fieldId, &targetClass)) {
        return env->GetStaticCharField(targetClass, fieldId);
    }
    return 0;
}

JNIEXPORT void JNICALL Java_com_deimos_bindings_JniAccessor_setStaticChar
        (JNIEnv *env, jclass clazz, jchar newChar, jstring jClassName, jstring jFieldName, jstring jSignature) {
    jfieldID fieldId;
    jclass targetClass;
    if (getStaticFieldId(env, jClassName, jFieldName, jSignature, &fieldId, &targetClass)) {
        env->SetStaticCharField(targetClass, fieldId, newChar);
    }
}

JNIEXPORT jobject JNICALL Java_com_deimos_bindings_JniAccessor_getInstanceObject
        (JNIEnv *env, jclass clazz, jobject instance, jstring jFieldName, jstring jSignature) {
    jfieldID fieldId;
    if (getInstanceFieldId(env, instance, jFieldName, jSignature, &fieldId)) {
        return env->GetObjectField(instance, fieldId);
    }
    return nullptr;
}

JNIEXPORT void JNICALL Java_com_deimos_bindings_JniAccessor_setInstanceObject
        (JNIEnv *env, jclass clazz, jobject newObject, jobject instance, jstring jFieldName, jstring jSignature) {
    jfieldID fieldId;
    if (getInstanceFieldId(env, instance, jFieldName, jSignature, &fieldId)) {
        env->SetObjectField(instance, fieldId, newObject);
    }
}

JNIEXPORT jbyte JNICALL Java_com_deimos_bindings_JniAccessor_getInstanceByte
        (JNIEnv *env, jclass clazz, jobject instance, jstring jFieldName, jstring jSignature) {
    jfieldID fieldId;
    if (getInstanceFieldId(env, instance, jFieldName, jSignature, &fieldId)) {
        return env->GetByteField(instance, fieldId);
    }
    return 0;
}

JNIEXPORT void JNICALL Java_com_deimos_bindings_JniAccessor_setInstanceByte
        (JNIEnv *env, jclass clazz, jbyte newByte, jobject instance, jstring jFieldName, jstring jSignature) {
    jfieldID fieldId;
    if (getInstanceFieldId(env, instance, jFieldName, jSignature, &fieldId)) {
        env->SetByteField(instance, fieldId, newByte);
    }
}

JNIEXPORT jshort JNICALL Java_com_deimos_bindings_JniAccessor_getInstanceShort
        (JNIEnv *env, jclass clazz, jobject instance, jstring jFieldName, jstring jSignature) {
    jfieldID fieldId;
    if (getInstanceFieldId(env, instance, jFieldName, jSignature, &fieldId)) {
        return env->GetShortField(instance, fieldId);
    }
    return 0;
}

JNIEXPORT void JNICALL Java_com_deimos_bindings_JniAccessor_setInstanceShort
        (JNIEnv *env, jclass clazz, jshort newShort, jobject instance, jstring jFieldName, jstring jSignature) {
    jfieldID fieldId;
    if (getInstanceFieldId(env, instance, jFieldName, jSignature, &fieldId)) {
        env->SetShortField(instance, fieldId, newShort);
    }
}

JNIEXPORT jint JNICALL Java_com_deimos_bindings_JniAccessor_getInstanceInt
        (JNIEnv *env, jclass clazz, jobject instance, jstring jFieldName, jstring jSignature) {
    jfieldID fieldId;
    if (getInstanceFieldId(env, instance, jFieldName, jSignature, &fieldId)) {
        return env->GetIntField(instance, fieldId);
    }
    return 0;
}

JNIEXPORT void JNICALL Java_com_deimos_bindings_JniAccessor_setInstanceInt
        (JNIEnv *env, jclass clazz, jint newInt, jobject instance, jstring jFieldName, jstring jSignature) {
    jfieldID fieldId;
    if (getInstanceFieldId(env, instance, jFieldName, jSignature, &fieldId)) {
        env->SetIntField(instance, fieldId, newInt);
    }
}

JNIEXPORT jlong JNICALL Java_com_deimos_bindings_JniAccessor_getInstanceLong
        (JNIEnv *env, jclass clazz, jobject instance, jstring jFieldName, jstring jSignature) {
    jfieldID fieldId;
    if (getInstanceFieldId(env, instance, jFieldName, jSignature, &fieldId)) {
        return env->GetLongField(instance, fieldId);
    }
    return 0;
}

JNIEXPORT void JNICALL Java_com_deimos_bindings_JniAccessor_setInstanceLong
        (JNIEnv *env, jclass clazz, jlong newLong, jobject instance, jstring jFieldName, jstring jSignature) {
    jfieldID fieldId;
    if (getInstanceFieldId(env, instance, jFieldName, jSignature, &fieldId)) {
        env->SetLongField(instance, fieldId, newLong);
    }
}

JNIEXPORT jfloat JNICALL Java_com_deimos_bindings_JniAccessor_getInstanceFloat
        (JNIEnv *env, jclass clazz, jobject instance, jstring jFieldName, jstring jSignature) {
    jfieldID fieldId;
    if (getInstanceFieldId(env, instance, jFieldName, jSignature, &fieldId)) {
        return env->GetFloatField(instance, fieldId);
    }
    return 0.0f;
}

JNIEXPORT void JNICALL Java_com_deimos_bindings_JniAccessor_setInstanceFloat
        (JNIEnv *env, jclass clazz, jfloat newFloat, jobject instance, jstring jFieldName, jstring jSignature) {
    jfieldID fieldId;
    if (getInstanceFieldId(env, instance, jFieldName, jSignature, &fieldId)) {
        env->SetFloatField(instance, fieldId, newFloat);
    }
}

JNIEXPORT jdouble JNICALL Java_com_deimos_bindings_JniAccessor_getInstanceDouble
        (JNIEnv *env, jclass clazz, jobject instance, jstring jFieldName, jstring jSignature) {
    jfieldID fieldId;
    if (getInstanceFieldId(env, instance, jFieldName, jSignature, &fieldId)) {
        return env->GetDoubleField(instance, fieldId);
    }
    return 0.0;
}

JNIEXPORT void JNICALL Java_com_deimos_bindings_JniAccessor_setInstanceDouble
        (JNIEnv *env, jclass clazz, jdouble newDouble, jobject instance, jstring jFieldName, jstring jSignature) {
    jfieldID fieldId;
    if (getInstanceFieldId(env, instance, jFieldName, jSignature, &fieldId)) {
        env->SetDoubleField(instance, fieldId, newDouble);
    }
}

JNIEXPORT jboolean JNICALL Java_com_deimos_bindings_JniAccessor_getInstanceBoolean
        (JNIEnv *env, jclass clazz, jobject instance, jstring jFieldName, jstring jSignature) {
    jfieldID fieldId;
    if (getInstanceFieldId(env, instance, jFieldName, jSignature, &fieldId)) {
        return env->GetBooleanField(instance, fieldId);
    }
    return JNI_FALSE;
}

JNIEXPORT void JNICALL Java_com_deimos_bindings_JniAccessor_setInstanceBoolean
        (JNIEnv *env, jclass clazz, jboolean newBoolean, jobject instance, jstring jFieldName, jstring jSignature) {
    jfieldID fieldId;
    if (getInstanceFieldId(env, instance, jFieldName, jSignature, &fieldId)) {
        env->SetBooleanField(instance, fieldId, newBoolean);
    }
}

JNIEXPORT jchar JNICALL Java_com_deimos_bindings_JniAccessor_getInstanceChar
        (JNIEnv *env, jclass clazz, jobject instance, jstring jFieldName, jstring jSignature) {
    jfieldID fieldId;
    if (getInstanceFieldId(env, instance, jFieldName, jSignature, &fieldId)) {
        return env->GetCharField(instance, fieldId);
    }
    return 0;
}

/*
 * Class:     com_deimos_bindings_JniAccessor
 * Method:    setInstanceChar
 * Signature: (CLjava/lang/Object;Ljava/lang/String;Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_com_deimos_bindings_JniAccessor_setInstanceChar
        (JNIEnv *env, jclass clazz, jchar newChar, jobject instance, jstring jFieldName, jstring jSignature) {
    jfieldID fieldId;
    if (getInstanceFieldId(env, instance, jFieldName, jSignature, &fieldId)) {
        env->SetCharField(instance, fieldId, newChar);
    }
}

JNIEXPORT jobjectArray JNICALL Java_com_deimos_bindings_JniAccessor_getInstances
        (JNIEnv *env, jclass clazz, jstring jTargetClass) {
    if (jvmti == nullptr) {
        initialize(env);
    }

    jsize strLen = env->GetStringUTFLength(jTargetClass);
    char targetClassString[strLen + 1];
    jStringToString(env, jTargetClass, targetClassString, strLen);

    jclass targetClass = env->FindClass(targetClassString);
    if (targetClass == nullptr) {
        throwClassNotFoundError(env, targetClassString);
        return nullptr;
    }

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

JNIEXPORT void JNICALL Java_com_deimos_bindings_JniInvoker_invokeStaticVoidMethod
        (JNIEnv *env, jclass clazz, jstring jClassName, jstring jMethodName, jstring jSignature, jobjectArray args,
         jstring jParameterTypes) {
    jclass targetClass;
    jmethodID methodId;

    jsize parameterCount = env->GetStringUTFLength(jParameterTypes);
    char parameterTypes[parameterCount + 1];
    jStringToString(env, jParameterTypes, parameterTypes, parameterCount);

    jvalue jValues[parameterCount];

    if (getStaticMethodInvocationDetails(
            env, jClassName, jMethodName, jSignature, args,
            parameterTypes, &targetClass, &methodId, jValues
    )) {
        env->CallStaticVoidMethodA(targetClass, methodId, jValues);
    }
}

JNIEXPORT jobject JNICALL Java_com_deimos_bindings_JniInvoker_invokeStaticObjectMethod
        (JNIEnv *env, jclass clazz, jstring jClassName, jstring jMethodName, jstring jSignature, jobjectArray args,
         jstring jParameterTypes) {
    jclass targetClass;
    jmethodID methodId;

    jsize parameterCount = env->GetStringUTFLength(jParameterTypes);
    char parameterTypes[parameterCount + 1];
    jStringToString(env, jParameterTypes, parameterTypes, parameterCount);

    jvalue jValues[parameterCount];

    if (getStaticMethodInvocationDetails(
            env, jClassName, jMethodName, jSignature, args,
            parameterTypes, &targetClass, &methodId, jValues
    )) {
        return env->CallStaticObjectMethodA(targetClass, methodId, jValues);
    }

    return nullptr;
}

JNIEXPORT jboolean JNICALL Java_com_deimos_bindings_JniInvoker_invokeStaticBooleanMethod
        (JNIEnv *env, jclass clazz, jstring jClassName, jstring jMethodName, jstring jSignature, jobjectArray args,
         jstring jParameterTypes) {
    jclass targetClass;
    jmethodID methodId;

    jsize parameterCount = env->GetStringUTFLength(jParameterTypes);
    char parameterTypes[parameterCount + 1];
    jStringToString(env, jParameterTypes, parameterTypes, parameterCount);

    jvalue jValues[parameterCount];

    if (getStaticMethodInvocationDetails(
            env, jClassName, jMethodName, jSignature, args,
            parameterTypes, &targetClass, &methodId, jValues
    )) {
        return env->CallStaticBooleanMethodA(targetClass, methodId, jValues);
    }

    return JNI_FALSE;
}