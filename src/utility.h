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

std::string jStringToString(JNIEnv *env, jstring jStr);

jvmtiIterationControl JNICALL heapObjectCallback(jlong class_tag, jlong size, jlong *tag_ptr, void *user_data);


#endif //JNI_REFLECTION_UTILITY_H
