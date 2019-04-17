#ifndef JNI_REFLECTION_UTILITY_H
#define JNI_REFLECTION_UTILITY_H


#include <jvmti.h>
#include <string>


/**
 * Global JVMTI instance
 */
extern jvmtiEnv *jvmti;


void initialize(JNIEnv *env);

void throwError(JNIEnv *env, const std::string &message);

void throwError(JNIEnv *env, const std::string &errorClassName, const std::string &message);

void throwClassNotFoundError(JNIEnv *env, const std::string &className);

void throwFieldNotFoundError(JNIEnv *env, const std::string &className, const std::string &fieldName);

void throwMethodNotFoundError(JNIEnv *env, const std::string &className, const std::string &methodName);

void throwMethodSignatureError(JNIEnv *env, const std::string &errorMessage);

void throwConstructorNotFoundError(JNIEnv *env, const std::string &className, const std::string &constructorName);

std::string jStringToString(JNIEnv *env, jstring jStr);

jvmtiIterationControl JNICALL heapObjectCallback(jlong class_tag, jlong size, jlong *tag_ptr, void *user_data);

bool getStaticFieldId(JNIEnv *env, jstring jClassName, jstring jFieldName, jstring jSignature, jfieldID *fieldId,
                      jclass *targetClass);

bool getInstanceFieldId(JNIEnv *env, jobject instance, jstring jFieldName, jstring jSignature, jfieldID *fieldId);

bool getStaticMethodId(JNIEnv *env, jstring jClassName, jstring jMethodName, jstring jSignature, jmethodID *methodId,
                       jclass *targetClass);

bool getStaticMethodInvocationDetails
        (JNIEnv *env, jstring jClassName, jstring jMethodName, jstring jSignature, jobjectArray args,
         std::string &parameterTypes, jclass *targetClass, jmethodID *methodId, jvalue *jValues);

#endif //JNI_REFLECTION_UTILITY_H
