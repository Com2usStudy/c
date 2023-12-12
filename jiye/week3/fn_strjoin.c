#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//두 배열을 합치는 함수
char *fn_strjoin(const char *s1, const  char *s2);

int main(){
    //char* s1 = "hello";
    //char* s2 = "imjiye";
    char s1[11];
    char s2[11];

    printf("배열 두개 입력: ");
    fgets(s1, 10, stdin);
    fgets(s2, 10, stdin);


    printf("joined string: %s" , fn_strjoin(s1, s2));


}

char *fn_strjoin(const char *s1, const  char *s2){
    
    long int result_length = strlen(s1) + strlen(s2) + sizeof(char);

    //s1의 길이 + s2의길이 + 추후 널문자가 들어갈 공간 만큼 메모리를 할당해준다. 
    char* result = (char*)malloc(strlen(s1) + strlen(s2) + sizeof(char));
    if (result == NULL) {               //메모리 할당에 실패했을때 프로그램 종료 
        printf("Memory not allocated.\n");
        exit(0);
    }

    for(const char* s1_ptr = s1; *s1_ptr != '\0'; s1_ptr++){
        *result = *s1_ptr;
        result++;
    }

    for(const char* s2_ptr = s2; *s2_ptr != '\0'; s2_ptr++){
        *result = *s2_ptr;
        result++;
    }
    //배열의 마지막에 널문자를 추가해준다. 
    *result = '\0';
    //result의 주소를 다시 맨 앞으로 돌려준다. 
    result -= (result_length-1);

    return result;
}
