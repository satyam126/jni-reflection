#include <jni.h>


#ifndef _Included_com_jnireflection_bindings_JNIAccessor
#define _Included_com_jnireflection_bindings_JNIAccessor
#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT jobject JNICALL Java_com_jnireflection_bindings_JNIAccessor_getStaticObject
        (JNIEnv *, jclass, jstring, jstring, jstring);

JNIEXPORT void JNICALL Java_com_jnireflection_bindings_JNIAccessor_setStaticObject
        (JNIEnv *, jclass, jobject, jstring, jstring, jstring);

JNIEXPORT jbyte JNICALL Java_com_jnireflection_bindings_JNIAccessor_getStaticByte
        (JNIEnv *, jclass, jstring, jstring, jstring);

JNIEXPORT void JNICALL Java_com_jnireflection_bindings_JNIAccessor_setStaticByte
        (JNIEnv *, jclass, jbyte, jstring, jstring, jstring);

JNIEXPORT jshort JNICALL Java_com_jnireflection_bindings_JNIAccessor_getStaticShort
        (JNIEnv *, jclass, jstring, jstring, jstring);

JNIEXPORT void JNICALL Java_com_jnireflection_bindings_JNIAccessor_setStaticShort
        (JNIEnv *, jclass, jshort, jstring, jstring, jstring);

JNIEXPORT jint JNICALL Java_com_jnireflection_bindings_JNIAccessor_getStaticInt
        (JNIEnv *, jclass, jstring, jstring, jstring);

JNIEXPORT void JNICALL Java_com_jnireflection_bindings_JNIAccessor_setStaticInt
        (JNIEnv *, jclass, jint, jstring, jstring, jstring);

JNIEXPORT jlong JNICALL Java_com_jnireflection_bindings_JNIAccessor_getStaticLong
        (JNIEnv *, jclass, jstring, jstring, jstring);

JNIEXPORT void JNICALL Java_com_jnireflection_bindings_JNIAccessor_setStaticLong
        (JNIEnv *, jclass, jlong, jstring, jstring, jstring);

JNIEXPORT jfloat JNICALL Java_com_jnireflection_bindings_JNIAccessor_getStaticFloat
        (JNIEnv *, jclass, jstring, jstring, jstring);

JNIEXPORT void JNICALL Java_com_jnireflection_bindings_JNIAccessor_setStaticFloat
        (JNIEnv *, jclass, jfloat, jstring, jstring, jstring);

JNIEXPORT jdouble JNICALL Java_com_jnireflection_bindings_JNIAccessor_getStaticDouble
        (JNIEnv *, jclass, jstring, jstring, jstring);

JNIEXPORT void JNICALL Java_com_jnireflection_bindings_JNIAccessor_setStaticDouble
        (JNIEnv *, jclass, jdouble, jstring, jstring, jstring);

JNIEXPORT jboolean JNICALL Java_com_jnireflection_bindings_JNIAccessor_getStaticBoolean
        (JNIEnv *, jclass, jstring, jstring, jstring);

JNIEXPORT void JNICALL Java_com_jnireflection_bindings_JNIAccessor_setStaticBoolean
        (JNIEnv *, jclass, jboolean, jstring, jstring, jstring);

JNIEXPORT jchar JNICALL Java_com_jnireflection_bindings_JNIAccessor_getStaticChar
        (JNIEnv *, jclass, jstring, jstring, jstring);

JNIEXPORT void JNICALL Java_com_jnireflection_bindings_JNIAccessor_setStaticChar
        (JNIEnv *, jclass, jchar, jstring, jstring, jstring);

JNIEXPORT jobject JNICALL Java_com_jnireflection_bindings_JNIAccessor_getInstanceObject
        (JNIEnv *, jclass, jobject, jstring, jstring);

JNIEXPORT void JNICALL Java_com_jnireflection_bindings_JNIAccessor_setInstanceObject
        (JNIEnv *, jclass, jobject, jobject, jstring, jstring);

JNIEXPORT jbyte JNICALL Java_com_jnireflection_bindings_JNIAccessor_getInstanceByte
        (JNIEnv *, jclass, jobject, jstring, jstring);

JNIEXPORT void JNICALL Java_com_jnireflection_bindings_JNIAccessor_setInstanceByte
        (JNIEnv *, jclass, jbyte, jobject, jstring, jstring);

JNIEXPORT jshort JNICALL Java_com_jnireflection_bindings_JNIAccessor_getInstanceShort
        (JNIEnv *, jclass, jobject, jstring, jstring);

JNIEXPORT void JNICALL Java_com_jnireflection_bindings_JNIAccessor_setInstanceShort
        (JNIEnv *, jclass, jshort, jobject, jstring, jstring);

JNIEXPORT jint JNICALL Java_com_jnireflection_bindings_JNIAccessor_getInstanceInt
        (JNIEnv *, jclass, jobject, jstring, jstring);

JNIEXPORT void JNICALL Java_com_jnireflection_bindings_JNIAccessor_setInstanceInt
        (JNIEnv *, jclass, jint, jobject, jstring, jstring);

JNIEXPORT jlong JNICALL Java_com_jnireflection_bindings_JNIAccessor_getInstanceLong
        (JNIEnv *, jclass, jobject, jstring, jstring);

JNIEXPORT void JNICALL Java_com_jnireflection_bindings_JNIAccessor_setInstanceLong
        (JNIEnv *, jclass, jlong, jobject, jstring, jstring);

JNIEXPORT jfloat JNICALL Java_com_jnireflection_bindings_JNIAccessor_getInstanceFloat
        (JNIEnv *, jclass, jobject, jstring, jstring);

JNIEXPORT void JNICALL Java_com_jnireflection_bindings_JNIAccessor_setInstanceFloat
        (JNIEnv *, jclass, jfloat, jobject, jstring, jstring);

JNIEXPORT jdouble JNICALL Java_com_jnireflection_bindings_JNIAccessor_getInstanceDouble
        (JNIEnv *, jclass, jobject, jstring, jstring);

JNIEXPORT void JNICALL Java_com_jnireflection_bindings_JNIAccessor_setInstanceDouble
        (JNIEnv *, jclass, jdouble, jobject, jstring, jstring);

JNIEXPORT jboolean JNICALL Java_com_jnireflection_bindings_JNIAccessor_getInstanceBoolean
        (JNIEnv *, jclass, jobject, jstring, jstring);

JNIEXPORT void JNICALL Java_com_jnireflection_bindings_JNIAccessor_setInstanceBoolean
        (JNIEnv *, jclass, jboolean, jobject, jstring, jstring);

JNIEXPORT jchar JNICALL Java_com_jnireflection_bindings_JNIAccessor_getInstanceChar
        (JNIEnv *, jclass, jobject, jstring, jstring);

JNIEXPORT void JNICALL Java_com_jnireflection_bindings_JNIAccessor_setInstanceChar
        (JNIEnv *, jclass, jchar, jobject, jstring, jstring);

JNIEXPORT jobject JNICALL Java_com_jnireflection_bindings_JNIInvoker_invokeStaticObjectMethod
        (JNIEnv *, jclass, jstring, jstring, jstring, jobjectArray, jstring);

JNIEXPORT jobjectArray JNICALL Java_com_jnireflection_bindings_JNIAccessor_getInstances
        (JNIEnv *, jclass, jstring);

#ifdef __cplusplus
}
#endif
#endif
