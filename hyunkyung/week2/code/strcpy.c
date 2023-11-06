#include <stdio.h>

char* fn_strcpy(char* pd, const char* ps); // Change the return type to char*

int main()
{
    char str[80] = "strawberry";

    printf("바꾸기 전 문자열 : %s\n", str);
    fn_strcpy(str, "apple");
    printf("바꾼 문자열 : %s\n", str);

    char* result = fn_strcpy(str, "kiwi"); // Capture the returned pointer
    printf("다른 문자열 대입 : %s\n", result);

    return 0;
}

char* fn_strcpy(char* pd, const char* ps)
{
    char* p0 = pd; // Store the start of the destination string

    while (*ps != '\0')
    {
        *pd = *ps;
        pd++;
        ps++;
    }
    *pd = '\0';

    return p0; // Return the start of the destination string
}


/*
#include <stdio.h>

void fn_strcpy(char* pd, char* ps);//함수 선언

int main()
{
	char str[80] = "strawberry";

	printf("바꾸기 전 문자열 : %s\n", str);
	fn_strcpy(str, "apple");               //문자열 "apple" 복사
	printf("바꾼 문자열 : %s\n", str);
	printf("다른 문자열 대입 : %s\n", fn_strcpy(str, "kiwi"));//반환값으로 출력

return 0;
}

void fn_strcpy(char* pd, char* ps)     //복사받을 곳(pd)과 복사할 곳(ps)의 포인터
{
	char* p0 = pd;    //pd 값을 나중에 반환하기 위해 보관

	while(*ps != '\0')//ps가 가리키는 문자가 널 문자가 아닌 동안
	{
	*pd = *ps;        //ps가 가리키는 문자를 pd가 가리키는 위치에 대입
	pd++;             //복사 받을 다음 위치로 포인터 증가
	ps++;             //복사할 다음 문자의 위치로 포인터 증가
	}
	*pd = '\0';       //복사가 모두 끝난 후 복사 받을 곳에 널 문자로 마무리

	return p0;        //복사가 끝난 저장 공간의 시작 주소 반환
}*/