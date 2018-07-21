#include <iostream>
#include <stdio.h>

#include "jni-reflection.h"


JNIEXPORT void JNICALL Java_test_Main_printHello(JNIEnv *, jclass) {
    std::cout << "hi" << std::endl;
    printf("hi\n");
}