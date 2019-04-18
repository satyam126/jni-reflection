#include <jni.h>


#ifndef _Included_com_deimos_binding_Accessor
#define _Included_com_deimos_binding_Accessor
#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT jobject JNICALL Java_com_deimos_binding_Accessor_getStaticObject
        (JNIEnv *, jclass, jstring, jstring, jstring);

JNIEXPORT void JNICALL Java_com_deimos_binding_Accessor_setStaticObject
        (JNIEnv *, jclass, jobject, jstring, jstring, jstring);

JNIEXPORT jbyte JNICALL Java_com_deimos_binding_Accessor_getStaticByte
        (JNIEnv *, jclass, jstring, jstring, jstring);

JNIEXPORT void JNICALL Java_com_deimos_binding_Accessor_setStaticByte
        (JNIEnv *, jclass, jbyte, jstring, jstring, jstring);

JNIEXPORT jshort JNICALL Java_com_deimos_binding_Accessor_getStaticShort
        (JNIEnv *, jclass, jstring, jstring, jstring);

JNIEXPORT void JNICALL Java_com_deimos_binding_Accessor_setStaticShort
        (JNIEnv *, jclass, jshort, jstring, jstring, jstring);

JNIEXPORT jint JNICALL Java_com_deimos_binding_Accessor_getStaticInt
        (JNIEnv *, jclass, jstring, jstring, jstring);

JNIEXPORT void JNICALL Java_com_deimos_binding_Accessor_setStaticInt
        (JNIEnv *, jclass, jint, jstring, jstring, jstring);

JNIEXPORT jlong JNICALL Java_com_deimos_binding_Accessor_getStaticLong
        (JNIEnv *, jclass, jstring, jstring, jstring);

JNIEXPORT void JNICALL Java_com_deimos_binding_Accessor_setStaticLong
        (JNIEnv *, jclass, jlong, jstring, jstring, jstring);

JNIEXPORT jfloat JNICALL Java_com_deimos_binding_Accessor_getStaticFloat
        (JNIEnv *, jclass, jstring, jstring, jstring);

JNIEXPORT void JNICALL Java_com_deimos_binding_Accessor_setStaticFloat
        (JNIEnv *, jclass, jfloat, jstring, jstring, jstring);

JNIEXPORT jdouble JNICALL Java_com_deimos_binding_Accessor_getStaticDouble
        (JNIEnv *, jclass, jstring, jstring, jstring);

JNIEXPORT void JNICALL Java_com_deimos_binding_Accessor_setStaticDouble
        (JNIEnv *, jclass, jdouble, jstring, jstring, jstring);

JNIEXPORT jboolean JNICALL Java_com_deimos_binding_Accessor_getStaticBoolean
        (JNIEnv *, jclass, jstring, jstring, jstring);

JNIEXPORT void JNICALL Java_com_deimos_binding_Accessor_setStaticBoolean
        (JNIEnv *, jclass, jboolean, jstring, jstring, jstring);

JNIEXPORT jchar JNICALL Java_com_deimos_binding_Accessor_getStaticChar
        (JNIEnv *, jclass, jstring, jstring, jstring);

JNIEXPORT void JNICALL Java_com_deimos_binding_Accessor_setStaticChar
        (JNIEnv *, jclass, jchar, jstring, jstring, jstring);

JNIEXPORT jobject JNICALL Java_com_deimos_binding_Accessor_getInstanceObject
        (JNIEnv *, jclass, jobject, jstring, jstring);

JNIEXPORT void JNICALL Java_com_deimos_binding_Accessor_setInstanceObject
        (JNIEnv *, jclass, jobject, jobject, jstring, jstring);

JNIEXPORT jbyte JNICALL Java_com_deimos_binding_Accessor_getInstanceByte
        (JNIEnv *, jclass, jobject, jstring, jstring);

JNIEXPORT void JNICALL Java_com_deimos_binding_Accessor_setInstanceByte
        (JNIEnv *, jclass, jbyte, jobject, jstring, jstring);

JNIEXPORT jshort JNICALL Java_com_deimos_binding_Accessor_getInstanceShort
        (JNIEnv *, jclass, jobject, jstring, jstring);

JNIEXPORT void JNICALL Java_com_deimos_binding_Accessor_setInstanceShort
        (JNIEnv *, jclass, jshort, jobject, jstring, jstring);

JNIEXPORT jint JNICALL Java_com_deimos_binding_Accessor_getInstanceInt
        (JNIEnv *, jclass, jobject, jstring, jstring);

JNIEXPORT void JNICALL Java_com_deimos_binding_Accessor_setInstanceInt
        (JNIEnv *, jclass, jint, jobject, jstring, jstring);

JNIEXPORT jlong JNICALL Java_com_deimos_binding_Accessor_getInstanceLong
        (JNIEnv *, jclass, jobject, jstring, jstring);

JNIEXPORT void JNICALL Java_com_deimos_binding_Accessor_setInstanceLong
        (JNIEnv *, jclass, jlong, jobject, jstring, jstring);

JNIEXPORT jfloat JNICALL Java_com_deimos_binding_Accessor_getInstanceFloat
        (JNIEnv *, jclass, jobject, jstring, jstring);

JNIEXPORT void JNICALL Java_com_deimos_binding_Accessor_setInstanceFloat
        (JNIEnv *, jclass, jfloat, jobject, jstring, jstring);

JNIEXPORT jdouble JNICALL Java_com_deimos_binding_Accessor_getInstanceDouble
        (JNIEnv *, jclass, jobject, jstring, jstring);

JNIEXPORT void JNICALL Java_com_deimos_binding_Accessor_setInstanceDouble
        (JNIEnv *, jclass, jdouble, jobject, jstring, jstring);

JNIEXPORT jboolean JNICALL Java_com_deimos_binding_Accessor_getInstanceBoolean
        (JNIEnv *, jclass, jobject, jstring, jstring);

JNIEXPORT void JNICALL Java_com_deimos_binding_Accessor_setInstanceBoolean
        (JNIEnv *, jclass, jboolean, jobject, jstring, jstring);

JNIEXPORT jchar JNICALL Java_com_deimos_binding_Accessor_getInstanceChar
        (JNIEnv *, jclass, jobject, jstring, jstring);

JNIEXPORT void JNICALL Java_com_deimos_binding_Accessor_setInstanceChar
        (JNIEnv *, jclass, jchar, jobject, jstring, jstring);

JNIEXPORT jobjectArray JNICALL Java_com_deimos_binding_Accessor_getInstances
        (JNIEnv *, jclass, jstring);

JNIEXPORT void JNICALL Java_com_deimos_binding_Invoker_invokeStaticVoidMethod
        (JNIEnv *, jclass, jstring, jstring, jstring, jobjectArray, jstring);

JNIEXPORT jobject JNICALL Java_com_deimos_binding_Invoker_invokeStaticObjectMethod
        (JNIEnv *, jclass, jstring, jstring, jstring, jobjectArray, jstring);

JNIEXPORT jboolean JNICALL Java_com_deimos_binding_Invoker_invokeStaticBooleanMethod
        (JNIEnv *, jclass, jstring, jstring, jstring, jobjectArray, jstring);

#ifdef __cplusplus
}
#endif
#endif
