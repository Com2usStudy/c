#include <stdio.h>

//int argc : main함수에 전달되는 인수의 개수
//char* argv[] : main함수에 전달되는 문자열의 배열. 첫 번째 문자열은 프로그램의 실행경로로 고정됨
int main(int argc, char* argv[]){
    for(int i = 0; i<argc-1 ; i++){
        printf("%s\n", argv[i+1]);
    }
}