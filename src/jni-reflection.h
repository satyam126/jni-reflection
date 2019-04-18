#include <jni.h>


#ifndef _Included_com_deimos_bindings_JniAccessor
#define _Included_com_deimos_bindings_JniAccessor
#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT jobject JNICALL Java_com_deimos_bindings_JniAccessor_getStaticObject
        (JNIEnv *, jclass, jstring, jstring, jstring);

JNIEXPORT void JNICALL Java_com_deimos_bindings_JniAccessor_setStaticObject
        (JNIEnv *, jclass, jobject, jstring, jstring, jstring);

JNIEXPORT jbyte JNICALL Java_com_deimos_bindings_JniAccessor_getStaticByte
        (JNIEnv *, jclass, jstring, jstring, jstring);

JNIEXPORT void JNICALL Java_com_deimos_bindings_JniAccessor_setStaticByte
        (JNIEnv *, jclass, jbyte, jstring, jstring, jstring);

JNIEXPORT jshort JNICALL Java_com_deimos_bindings_JniAccessor_getStaticShort
        (JNIEnv *, jclass, jstring, jstring, jstring);

JNIEXPORT void JNICALL Java_com_deimos_bindings_JniAccessor_setStaticShort
        (JNIEnv *, jclass, jshort, jstring, jstring, jstring);

JNIEXPORT jint JNICALL Java_com_deimos_bindings_JniAccessor_getStaticInt
        (JNIEnv *, jclass, jstring, jstring, jstring);

JNIEXPORT void JNICALL Java_com_deimos_bindings_JniAccessor_setStaticInt
        (JNIEnv *, jclass, jint, jstring, jstring, jstring);

JNIEXPORT jlong JNICALL Java_com_deimos_bindings_JniAccessor_getStaticLong
        (JNIEnv *, jclass, jstring, jstring, jstring);

JNIEXPORT void JNICALL Java_com_deimos_bindings_JniAccessor_setStaticLong
        (JNIEnv *, jclass, jlong, jstring, jstring, jstring);

JNIEXPORT jfloat JNICALL Java_com_deimos_bindings_JniAccessor_getStaticFloat
        (JNIEnv *, jclass, jstring, jstring, jstring);

JNIEXPORT void JNICALL Java_com_deimos_bindings_JniAccessor_setStaticFloat
        (JNIEnv *, jclass, jfloat, jstring, jstring, jstring);

JNIEXPORT jdouble JNICALL Java_com_deimos_bindings_JniAccessor_getStaticDouble
        (JNIEnv *, jclass, jstring, jstring, jstring);

JNIEXPORT void JNICALL Java_com_deimos_bindings_JniAccessor_setStaticDouble
        (JNIEnv *, jclass, jdouble, jstring, jstring, jstring);

JNIEXPORT jboolean JNICALL Java_com_deimos_bindings_JniAccessor_getStaticBoolean
        (JNIEnv *, jclass, jstring, jstring, jstring);

JNIEXPORT void JNICALL Java_com_deimos_bindings_JniAccessor_setStaticBoolean
        (JNIEnv *, jclass, jboolean, jstring, jstring, jstring);

JNIEXPORT jchar JNICALL Java_com_deimos_bindings_JniAccessor_getStaticChar
        (JNIEnv *, jclass, jstring, jstring, jstring);

JNIEXPORT void JNICALL Java_com_deimos_bindings_JniAccessor_setStaticChar
        (JNIEnv *, jclass, jchar, jstring, jstring, jstring);

JNIEXPORT jobject JNICALL Java_com_deimos_bindings_JniAccessor_getInstanceObject
        (JNIEnv *, jclass, jobject, jstring, jstring);

JNIEXPORT void JNICALL Java_com_deimos_bindings_JniAccessor_setInstanceObject
        (JNIEnv *, jclass, jobject, jobject, jstring, jstring);

JNIEXPORT jbyte JNICALL Java_com_deimos_bindings_JniAccessor_getInstanceByte
        (JNIEnv *, jclass, jobject, jstring, jstring);

JNIEXPORT void JNICALL Java_com_deimos_bindings_JniAccessor_setInstanceByte
        (JNIEnv *, jclass, jbyte, jobject, jstring, jstring);

JNIEXPORT jshort JNICALL Java_com_deimos_bindings_JniAccessor_getInstanceShort
        (JNIEnv *, jclass, jobject, jstring, jstring);

JNIEXPORT void JNICALL Java_com_deimos_bindings_JniAccessor_setInstanceShort
        (JNIEnv *, jclass, jshort, jobject, jstring, jstring);

JNIEXPORT jint JNICALL Java_com_deimos_bindings_JniAccessor_getInstanceInt
        (JNIEnv *, jclass, jobject, jstring, jstring);

JNIEXPORT void JNICALL Java_com_deimos_bindings_JniAccessor_setInstanceInt
        (JNIEnv *, jclass, jint, jobject, jstring, jstring);

JNIEXPORT jlong JNICALL Java_com_deimos_bindings_JniAccessor_getInstanceLong
        (JNIEnv *, jclass, jobject, jstring, jstring);

JNIEXPORT void JNICALL Java_com_deimos_bindings_JniAccessor_setInstanceLong
        (JNIEnv *, jclass, jlong, jobject, jstring, jstring);

JNIEXPORT jfloat JNICALL Java_com_deimos_bindings_JniAccessor_getInstanceFloat
        (JNIEnv *, jclass, jobject, jstring, jstring);

JNIEXPORT void JNICALL Java_com_deimos_bindings_JniAccessor_setInstanceFloat
        (JNIEnv *, jclass, jfloat, jobject, jstring, jstring);

JNIEXPORT jdouble JNICALL Java_com_deimos_bindings_JniAccessor_getInstanceDouble
        (JNIEnv *, jclass, jobject, jstring, jstring);

JNIEXPORT void JNICALL Java_com_deimos_bindings_JniAccessor_setInstanceDouble
        (JNIEnv *, jclass, jdouble, jobject, jstring, jstring);

JNIEXPORT jboolean JNICALL Java_com_deimos_bindings_JniAccessor_getInstanceBoolean
        (JNIEnv *, jclass, jobject, jstring, jstring);

JNIEXPORT void JNICALL Java_com_deimos_bindings_JniAccessor_setInstanceBoolean
        (JNIEnv *, jclass, jboolean, jobject, jstring, jstring);

JNIEXPORT jchar JNICALL Java_com_deimos_bindings_JniAccessor_getInstanceChar
        (JNIEnv *, jclass, jobject, jstring, jstring);

JNIEXPORT void JNICALL Java_com_deimos_bindings_JniAccessor_setInstanceChar
        (JNIEnv *, jclass, jchar, jobject, jstring, jstring);

JNIEXPORT jobjectArray JNICALL Java_com_deimos_bindings_JniAccessor_getInstances
        (JNIEnv *, jclass, jstring);

JNIEXPORT void JNICALL Java_com_deimos_bindings_JniInvoker_invokeStaticVoidMethod
        (JNIEnv *, jclass, jstring, jstring, jstring, jobjectArray, jstring);

JNIEXPORT jobject JNICALL Java_com_deimos_bindings_JniInvoker_invokeStaticObjectMethod
        (JNIEnv *, jclass, jstring, jstring, jstring, jobjectArray, jstring);

JNIEXPORT jboolean JNICALL Java_com_deimos_bindings_JniInvoker_invokeStaticBooleanMethod
        (JNIEnv *, jclass, jstring, jstring, jstring, jobjectArray, jstring);

#ifdef __cplusplus
}
#endif
#endif
