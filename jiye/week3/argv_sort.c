#include <stdio.h>
#include <string.h>


//문자열을 담은 배열과 배열의 길이를 매개변수로 받으면 배열의 내용물(문자열)을 정리해 출력해준다. 
void array_bubble_sort(char *arr[], int length);

//int argc : main함수에 전달되는 인수의 개수
//char* argv[] : main함수에 전달되는 문자열의 배열. 첫 번째 문자열은 프로그램의 실행경로로 고정됨
int main(int argc, char* argv[]){

    argv++;     //첫 번째 인수는 프로그램의 실행경로이므로 다음 인덱스로 감
    array_bubble_sort(argv, argc-1);

}

void array_bubble_sort(char *arr[], int length){
    char temp[20];

    for (int i = 0; i < length-1; i++){
        for (int j = 0; j < length-1 - i; j++)
        {
            if (strcmp(*(arr + j), *(arr + j +1)) > 0)  //앞 문자열이 더 클때
            {   //swap 해준다.
                //strcpy 함수는 인자로 받은 포인터 자체의 값을 바꾸는 게 아니라
                //포인터가 가리키는 곳의 값을 바꾸는 것이므로 포인터 상수를 넘겨줘도 상관없다. 
                strcpy(temp, *(arr + j));
                strcpy(*(arr + j), *(arr + j +1));
                strcpy(*(arr + j + 1), temp);
            }
        }
    }

    //정렬된 인수 출력
    for(int i = 0; i<length ; i++){
        printf("%s\n", arr[i]);
    }
}

