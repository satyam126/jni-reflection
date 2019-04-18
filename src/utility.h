#ifndef JNI_REFLECTION_UTILITY_H
#define JNI_REFLECTION_UTILITY_H


#include <jvmti.h>
#include <string>


/**
 * Global JVMTI instance
 */
extern jvmtiEnv *jvmti;


void initialize(JNIEnv *env);

void throwError(JNIEnv *env, const char *message);

void throwError(JNIEnv *env, const char *errorClassName, const char *message);

void throwClassNotFoundError(JNIEnv *env, const char *className);

void throwFieldNotFoundError(JNIEnv *env, const char *className, const char *fieldName);

void throwMethodNotFoundError(JNIEnv *env, const char *className, const char *methodName);

void throwMethodSignatureError(JNIEnv *env, const char *errorMessage);

void throwConstructorNotFoundError(JNIEnv *env, const char *className, const char *constructorName);

bool jStringToString(JNIEnv *env, jstring inJStr, char *outStr, jsize strLength);

jvmtiIterationControl JNICALL heapObjectCallback(jlong class_tag, jlong size, jlong *tag_ptr, void *user_data);

bool getStaticFieldId(JNIEnv *env, jstring jClassName, jstring jFieldName, jstring jSignature, jfieldID *fieldId,
                      jclass *targetClass);

bool getInstanceFieldId(JNIEnv *env, jobject instance, jstring jFieldName, jstring jSignature, jfieldID *fieldId);

bool getStaticMethodId(JNIEnv *env, jstring jClassName, jstring jMethodName, jstring jSignature, jmethodID *methodId,
                       jclass *targetClass);

bool getStaticMethodInvocationDetails
        (JNIEnv *env, jstring jClassName, jstring jMethodName, jstring jSignature, jobjectArray args,
         char *parameterTypes, jclass *targetClass, jmethodID *methodId, jvalue *jValues);

#endif //JNI_REFLECTION_UTILITY_H
