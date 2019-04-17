#include <iostream>
#include <sstream>

#include "utility.h"
#include "jni-reflection.h"


JNIEXPORT jobject JNICALL Java_com_jnireflection_bindings_JNIAccessor_getStaticObject
        (JNIEnv *env, jclass clazz, jstring jClassName, jstring jFieldName, jstring jSignature) {
    jfieldID fieldId;
    jclass targetClass;
    if (getStaticFieldId(env, jClassName, jFieldName, jSignature, &fieldId, &targetClass)) {
        return env->GetStaticObjectField(targetClass, fieldId);
    }
    return nullptr;
}

JNIEXPORT void JNICALL Java_com_jnireflection_bindings_JNIAccessor_setStaticObject
        (JNIEnv *env, jclass clazz, jobject newObject, jstring jClassName, jstring jFieldName, jstring jSignature) {
    jfieldID fieldId;
    jclass targetClass;
    if (getStaticFieldId(env, jClassName, jFieldName, jSignature, &fieldId, &targetClass)) {
        env->SetStaticObjectField(targetClass, fieldId, newObject);
    }
}

JNIEXPORT jbyte JNICALL Java_com_jnireflection_bindings_JNIAccessor_getStaticByte
        (JNIEnv *env, jclass clazz, jstring jClassName, jstring jFieldName, jstring jSignature) {
    jfieldID fieldId;
    jclass targetClass;
    if (getStaticFieldId(env, jClassName, jFieldName, jSignature, &fieldId, &targetClass)) {
        return env->GetStaticByteField(targetClass, fieldId);
    }
    return 0;
}

JNIEXPORT void JNICALL Java_com_jnireflection_bindings_JNIAccessor_setStaticByte
        (JNIEnv *env, jclass clazz, jbyte newByte, jstring jClassName, jstring jFieldName, jstring jSignature) {
    jfieldID fieldId;
    jclass targetClass;
    if (getStaticFieldId(env, jClassName, jFieldName, jSignature, &fieldId, &targetClass)) {
        env->SetStaticByteField(targetClass, fieldId, newByte);
    }
}

JNIEXPORT jshort JNICALL Java_com_jnireflection_bindings_JNIAccessor_getStaticShort
        (JNIEnv *env, jclass clazz, jstring jClassName, jstring jFieldName, jstring jSignature) {
    jfieldID fieldId;
    jclass targetClass;
    if (getStaticFieldId(env, jClassName, jFieldName, jSignature, &fieldId, &targetClass)) {
        return env->GetStaticShortField(targetClass, fieldId);
    }
    return 0;
}

JNIEXPORT void JNICALL Java_com_jnireflection_bindings_JNIAccessor_setStaticShort
        (JNIEnv *env, jclass clazz, jshort newShort, jstring jClassName, jstring jFieldName, jstring jSignature) {
    jfieldID fieldId;
    jclass targetClass;
    if (getStaticFieldId(env, jClassName, jFieldName, jSignature, &fieldId, &targetClass)) {
        env->SetStaticShortField(targetClass, fieldId, newShort);
    }
}

JNIEXPORT jint JNICALL Java_com_jnireflection_bindings_JNIAccessor_getStaticInt
        (JNIEnv *env, jclass clazz, jstring jClassName, jstring jFieldName, jstring jSignature) {
    jfieldID fieldId;
    jclass targetClass;
    if (getStaticFieldId(env, jClassName, jFieldName, jSignature, &fieldId, &targetClass)) {
        return env->GetStaticIntField(targetClass, fieldId);
    }
    return 0;
}

JNIEXPORT void JNICALL Java_com_jnireflection_bindings_JNIAccessor_setStaticInt
        (JNIEnv *env, jclass clazz, jint newInt, jstring jClassName, jstring jFieldName, jstring jSignature) {
    jfieldID fieldId;
    jclass targetClass;
    if (getStaticFieldId(env, jClassName, jFieldName, jSignature, &fieldId, &targetClass)) {
        env->SetStaticIntField(targetClass, fieldId, newInt);
    }
}

JNIEXPORT jlong JNICALL Java_com_jnireflection_bindings_JNIAccessor_getStaticLong
        (JNIEnv *env, jclass clazz, jstring jClassName, jstring jFieldName, jstring jSignature) {
    jfieldID fieldId;
    jclass targetClass;
    if (getStaticFieldId(env, jClassName, jFieldName, jSignature, &fieldId, &targetClass)) {
        return env->GetStaticLongField(targetClass, fieldId);
    }
    return 0;
}

JNIEXPORT void JNICALL Java_com_jnireflection_bindings_JNIAccessor_setStaticLong
        (JNIEnv *env, jclass clazz, jlong newLong, jstring jClassName, jstring jFieldName, jstring jSignature) {
    jfieldID fieldId;
    jclass targetClass;
    if (getStaticFieldId(env, jClassName, jFieldName, jSignature, &fieldId, &targetClass)) {
        env->SetStaticLongField(targetClass, fieldId, newLong);
    }
}

JNIEXPORT jfloat JNICALL Java_com_jnireflection_bindings_JNIAccessor_getStaticFloat
        (JNIEnv *env, jclass clazz, jstring jClassName, jstring jFieldName, jstring jSignature) {
    jfieldID fieldId;
    jclass targetClass;
    if (getStaticFieldId(env, jClassName, jFieldName, jSignature, &fieldId, &targetClass)) {
        return env->GetStaticFloatField(targetClass, fieldId);
    }
    return 0.0f;
}

JNIEXPORT void JNICALL Java_com_jnireflection_bindings_JNIAccessor_setStaticFloat
        (JNIEnv *env, jclass clazz, jfloat newFloat, jstring jClassName, jstring jFieldName, jstring jSignature) {
    jfieldID fieldId;
    jclass targetClass;
    if (getStaticFieldId(env, jClassName, jFieldName, jSignature, &fieldId, &targetClass)) {
        env->SetStaticFloatField(targetClass, fieldId, newFloat);
    }
}

JNIEXPORT jdouble JNICALL Java_com_jnireflection_bindings_JNIAccessor_getStaticDouble
        (JNIEnv *env, jclass clazz, jstring jClassName, jstring jFieldName, jstring jSignature) {
    jfieldID fieldId;
    jclass targetClass;
    if (getStaticFieldId(env, jClassName, jFieldName, jSignature, &fieldId, &targetClass)) {
        return env->GetStaticDoubleField(targetClass, fieldId);
    }
    return 0.0;
}

JNIEXPORT void JNICALL Java_com_jnireflection_bindings_JNIAccessor_setStaticDouble
        (JNIEnv *env, jclass clazz, jdouble newDouble, jstring jClassName, jstring jFieldName, jstring jSignature) {
    jfieldID fieldId;
    jclass targetClass;
    if (getStaticFieldId(env, jClassName, jFieldName, jSignature, &fieldId, &targetClass)) {
        env->SetStaticDoubleField(targetClass, fieldId, newDouble);
    }
}

JNIEXPORT jboolean JNICALL Java_com_jnireflection_bindings_JNIAccessor_getStaticBoolean
        (JNIEnv *env, jclass clazz, jstring jClassName, jstring jFieldName, jstring jSignature) {
    jfieldID fieldId;
    jclass targetClass;
    if (getStaticFieldId(env, jClassName, jFieldName, jSignature, &fieldId, &targetClass)) {
        return env->GetStaticBooleanField(targetClass, fieldId);
    }
    return JNI_FALSE;
}

JNIEXPORT void JNICALL Java_com_jnireflection_bindings_JNIAccessor_setStaticBoolean
        (JNIEnv *env, jclass clazz, jboolean newBoolean, jstring jClassName, jstring jFieldName, jstring jSignature) {
    jfieldID fieldId;
    jclass targetClass;
    if (getStaticFieldId(env, jClassName, jFieldName, jSignature, &fieldId, &targetClass)) {
        env->SetStaticBooleanField(targetClass, fieldId, newBoolean);
    }
}

JNIEXPORT jchar JNICALL Java_com_jnireflection_bindings_JNIAccessor_getStaticChar
        (JNIEnv *env, jclass clazz, jstring jClassName, jstring jFieldName, jstring jSignature) {
    jfieldID fieldId;
    jclass targetClass;
    if (getStaticFieldId(env, jClassName, jFieldName, jSignature, &fieldId, &targetClass)) {
        return env->GetStaticCharField(targetClass, fieldId);
    }
    return 0;
}

JNIEXPORT void JNICALL Java_com_jnireflection_bindings_JNIAccessor_setStaticChar
        (JNIEnv *env, jclass clazz, jchar newChar, jstring jClassName, jstring jFieldName, jstring jSignature) {
    jfieldID fieldId;
    jclass targetClass;
    if (getStaticFieldId(env, jClassName, jFieldName, jSignature, &fieldId, &targetClass)) {
        env->SetStaticCharField(targetClass, fieldId, newChar);
    }
}

JNIEXPORT jobject JNICALL Java_com_jnireflection_bindings_JNIAccessor_getInstanceObject
        (JNIEnv *env, jclass clazz, jobject instance, jstring jFieldName, jstring jSignature) {
    jfieldID fieldId;
    if (getInstanceFieldId(env, instance, jFieldName, jSignature, &fieldId)) {
        return env->GetObjectField(instance, fieldId);
    }
    return nullptr;
}

JNIEXPORT void JNICALL Java_com_jnireflection_bindings_JNIAccessor_setInstanceObject
        (JNIEnv *env, jclass clazz, jobject newObject, jobject instance, jstring jFieldName, jstring jSignature) {
    jfieldID fieldId;
    if (getInstanceFieldId(env, instance, jFieldName, jSignature, &fieldId)) {
        env->SetObjectField(instance, fieldId, newObject);
    }
}

JNIEXPORT jbyte JNICALL Java_com_jnireflection_bindings_JNIAccessor_getInstanceByte
        (JNIEnv *env, jclass clazz, jobject instance, jstring jFieldName, jstring jSignature) {
    jfieldID fieldId;
    if (getInstanceFieldId(env, instance, jFieldName, jSignature, &fieldId)) {
        return env->GetByteField(instance, fieldId);
    }
    return 0;
}

JNIEXPORT void JNICALL Java_com_jnireflection_bindings_JNIAccessor_setInstanceByte
        (JNIEnv *env, jclass clazz, jbyte newByte, jobject instance, jstring jFieldName, jstring jSignature) {
    jfieldID fieldId;
    if (getInstanceFieldId(env, instance, jFieldName, jSignature, &fieldId)) {
        env->SetByteField(instance, fieldId, newByte);
    }
}

JNIEXPORT jshort JNICALL Java_com_jnireflection_bindings_JNIAccessor_getInstanceShort
        (JNIEnv *env, jclass clazz, jobject instance, jstring jFieldName, jstring jSignature) {
    jfieldID fieldId;
    if (getInstanceFieldId(env, instance, jFieldName, jSignature, &fieldId)) {
        return env->GetShortField(instance, fieldId);
    }
    return 0;
}

JNIEXPORT void JNICALL Java_com_jnireflection_bindings_JNIAccessor_setInstanceShort
        (JNIEnv *env, jclass clazz, jshort newShort, jobject instance, jstring jFieldName, jstring jSignature) {
    jfieldID fieldId;
    if (getInstanceFieldId(env, instance, jFieldName, jSignature, &fieldId)) {
        env->SetShortField(instance, fieldId, newShort);
    }
}

JNIEXPORT jint JNICALL Java_com_jnireflection_bindings_JNIAccessor_getInstanceInt
        (JNIEnv *env, jclass clazz, jobject instance, jstring jFieldName, jstring jSignature) {
    jfieldID fieldId;
    if (getInstanceFieldId(env, instance, jFieldName, jSignature, &fieldId)) {
        return env->GetIntField(instance, fieldId);
    }
    return 0;
}

JNIEXPORT void JNICALL Java_com_jnireflection_bindings_JNIAccessor_setInstanceInt
        (JNIEnv *env, jclass clazz, jint newInt, jobject instance, jstring jFieldName, jstring jSignature) {
    jfieldID fieldId;
    if (getInstanceFieldId(env, instance, jFieldName, jSignature, &fieldId)) {
        env->SetIntField(instance, fieldId, newInt);
    }
}

JNIEXPORT jlong JNICALL Java_com_jnireflection_bindings_JNIAccessor_getInstanceLong
        (JNIEnv *env, jclass clazz, jobject instance, jstring jFieldName, jstring jSignature) {
    jfieldID fieldId;
    if (getInstanceFieldId(env, instance, jFieldName, jSignature, &fieldId)) {
        return env->GetLongField(instance, fieldId);
    }
    return 0;
}

JNIEXPORT void JNICALL Java_com_jnireflection_bindings_JNIAccessor_setInstanceLong
        (JNIEnv *env, jclass clazz, jlong newLong, jobject instance, jstring jFieldName, jstring jSignature) {
    jfieldID fieldId;
    if (getInstanceFieldId(env, instance, jFieldName, jSignature, &fieldId)) {
        env->SetLongField(instance, fieldId, newLong);
    }
}

JNIEXPORT jfloat JNICALL Java_com_jnireflection_bindings_JNIAccessor_getInstanceFloat
        (JNIEnv *env, jclass clazz, jobject instance, jstring jFieldName, jstring jSignature) {
    jfieldID fieldId;
    if (getInstanceFieldId(env, instance, jFieldName, jSignature, &fieldId)) {
        return env->GetFloatField(instance, fieldId);
    }
    return 0.0f;
}

JNIEXPORT void JNICALL Java_com_jnireflection_bindings_JNIAccessor_setInstanceFloat
        (JNIEnv *env, jclass clazz, jfloat newFloat, jobject instance, jstring jFieldName, jstring jSignature) {
    jfieldID fieldId;
    if (getInstanceFieldId(env, instance, jFieldName, jSignature, &fieldId)) {
        env->SetFloatField(instance, fieldId, newFloat);
    }
}

JNIEXPORT jdouble JNICALL Java_com_jnireflection_bindings_JNIAccessor_getInstanceDouble
        (JNIEnv *env, jclass clazz, jobject instance, jstring jFieldName, jstring jSignature) {
    jfieldID fieldId;
    if (getInstanceFieldId(env, instance, jFieldName, jSignature, &fieldId)) {
        return env->GetDoubleField(instance, fieldId);
    }
    return 0.0;
}

JNIEXPORT void JNICALL Java_com_jnireflection_bindings_JNIAccessor_setInstanceDouble
        (JNIEnv *env, jclass clazz, jdouble newDouble, jobject instance, jstring jFieldName, jstring jSignature) {
    jfieldID fieldId;
    if (getInstanceFieldId(env, instance, jFieldName, jSignature, &fieldId)) {
        env->SetDoubleField(instance, fieldId, newDouble);
    }
}

JNIEXPORT jboolean JNICALL Java_com_jnireflection_bindings_JNIAccessor_getInstanceBoolean
        (JNIEnv *env, jclass clazz, jobject instance, jstring jFieldName, jstring jSignature) {
    jfieldID fieldId;
    if (getInstanceFieldId(env, instance, jFieldName, jSignature, &fieldId)) {
        return env->GetBooleanField(instance, fieldId);
    }
    return JNI_FALSE;
}

JNIEXPORT void JNICALL Java_com_jnireflection_bindings_JNIAccessor_setInstanceBoolean
        (JNIEnv *env, jclass clazz, jboolean newBoolean, jobject instance, jstring jFieldName, jstring jSignature) {
    jfieldID fieldId;
    if (getInstanceFieldId(env, instance, jFieldName, jSignature, &fieldId)) {
        env->SetBooleanField(instance, fieldId, newBoolean);
    }
}

JNIEXPORT jchar JNICALL Java_com_jnireflection_bindings_JNIAccessor_getInstanceChar
        (JNIEnv *env, jclass clazz, jobject instance, jstring jFieldName, jstring jSignature) {
    jfieldID fieldId;
    if (getInstanceFieldId(env, instance, jFieldName, jSignature, &fieldId)) {
        return env->GetCharField(instance, fieldId);
    }
    return 0;
}

/*
 * Class:     com_jnireflection_bindings_JNIAccessor
 * Method:    setInstanceChar
 * Signature: (CLjava/lang/Object;Ljava/lang/String;Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_com_jnireflection_bindings_JNIAccessor_setInstanceChar
        (JNIEnv *env, jclass clazz, jchar newChar, jobject instance, jstring jFieldName, jstring jSignature) {
    jfieldID fieldId;
    if (getInstanceFieldId(env, instance, jFieldName, jSignature, &fieldId)) {
        env->SetCharField(instance, fieldId, newChar);
    }
}

JNIEXPORT jobjectArray JNICALL Java_com_jnireflection_bindings_JNIAccessor_getInstances
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

JNIEXPORT jobject JNICALL Java_com_jnireflection_bindings_JNIInvoker_invokeStaticObjectMethod
        (JNIEnv *env, jclass clazz, jstring jClassName, jstring jMethodName, jstring jSignature, jobjectArray args,
         jstring jParameterTypes) {
    jclass targetClass;
    jmethodID methodId;
    std::string parameterTypes = jStringToString(env, jParameterTypes);
    auto parameterCount = static_cast<unsigned long>(parameterTypes.length());
    jvalue jValues[parameterCount];

    if (getStaticMethodInvocationDetails(
            env, jClassName, jMethodName, jSignature, args,
            parameterTypes, &targetClass, &methodId, jValues
    )) {
        return env->CallStaticObjectMethodA(targetClass, methodId, jValues);
    }

    return nullptr;
}