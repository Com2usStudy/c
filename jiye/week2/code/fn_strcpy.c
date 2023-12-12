#include <stdio.h>

//문자열 src를 dest로 복사하는 함수
//오버플로우를 방지하기 위해서, dest가 가리키는 배열의 크기는 반드시 src문자열의 크기와 같거나 이보다 커야 한다. 
//또한, 복사하는 영역이 src와 겹치면 안된다.
char* fn_strcpy(char* dest, char* src);

int main(){
    char s1[] = "hello world!!";
    char s2[20];

    fn_strcpy(s2, s1);

    printf("s1: ");
    for(char* ptr_s1 = s1; *ptr_s1!='\0' ; ptr_s1++){
        printf("%c", *ptr_s1);
    }
    printf("\n");

    //원본 주솟값 출력해보기
    for(char* ptr_s1 = s1; *ptr_s1!='\0' ; ptr_s1++){
        printf("%p ", ptr_s1);
    }
    printf("\n");

    printf("s2: ");
    for(char* ptr_s2 = s2; *ptr_s2 !='\0' ; ptr_s2++){
        printf("%c", *ptr_s2);
    }
    printf("\n");

    //복사본 주솟값 출력해보기
    for(char* ptr_s2 = s2; *ptr_s2!='\0' ; ptr_s2++){
        printf("%p ", ptr_s2);
    }
    printf("\n");

}

char* fn_strcpy(char* dest, char* src){
    for(int i=0; *(src+i) !='\0' ; i++){
        *(dest+i) = *(src+i);
    }
    
    return dest; 
}
