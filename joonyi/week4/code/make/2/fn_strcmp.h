#ifndef FN_STRCMP
#define FN_STRCMP
#include <stdio.h>
#include <string.h>

// 널문자를 세지 않고 문자열의 길이를 구하는 함수
int get_length_const(const char* string);

// // 절대값 구하기
int abs(int number);


// 문자열 비교하기 (ASCII 값을 비교해서 비교 결과 리턴)
/*
* 
* -1 : string1 이 string2 보다 작음
* 0 : string1 이 string2 과 같음
* 1 : string1 이 string2 보다 큼
*/
int fn_strcmp(const char* string1, const char* string2);
#endif