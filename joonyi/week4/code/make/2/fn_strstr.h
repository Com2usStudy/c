#ifndef FN_STRSTR
#define FN_STRSTR
#include <string.h>
#include <stdio.h>

/*
abcde
abz

인자에 NULL 일 경우
*/

char* fn_strstr(const char* string1, const char* string2);

#endif