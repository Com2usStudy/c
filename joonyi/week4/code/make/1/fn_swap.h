#ifndef FN_SWAP
#define FN_SWAP
#include <unistd.h>

/*
ChatGPT 가 짜준 write() 함수로 포인터 출력하는 함수
*/
void print_address(void *ptr);

char *charValue(int a);

int getLength(int a);

/*
내가 짠 값 바꾸는 함수 
C는 call by value 이다.
*/
void fn_swap(int *a, int *b);

#endif