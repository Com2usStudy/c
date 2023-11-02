#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//malloc을 호출하여 string의 사본에 대한 기억장치 공간을 예약하는 함수 (strcpy에 추가적으로 메모리 할당을 해줌)
//복사된 스트링을 포함하는 기억장치 공간에 대한 포인터를 리턴한다. 
//기억장치를 예약할 수 없으면 strdup은 NULL을 리턴한다.
char* fn_strdup(const char *string);

int main(){
    char *string = "this is a hello";
    char *newstr;

    if ((newstr = fn_strdup(string)) != NULL)
        printf("The new string is: %s\n", newstr);
    free(newstr);
}

char* fn_strdup(const char *string){
    
    //string의 길이만큼(널문자 길이 포함) 메모리를 할당해줌
    //strlen() 함수는 종료 널 문자를 제외하고 string 길이를 판별하므로 sizeof(char)를 더해준다. 
    char* newstr = (char*)malloc(strlen(string) + sizeof(char));
    if (newstr == NULL) {               //메모리 할당에 실패했을때 NULL을 리턴한다. 
        printf("Memory not allocated.\n");
        return NULL;
    }

    //strcpy() 함수는 끝나는 널 문자를 포함하여 
    //string2를 string1에서 지정한 위치로 복사한다.
    strcpy(newstr, string);

    return newstr;
}
