#include <stdio.h>

//주소가 매개변수로 들어온 두 개의 정수의 값을 바꾸는 기능

//& : 주소 연산자, * : 참조 연산자
//선언할때의 *는 포인터형이라는 뜻이고, 변수 앞에 쓴 *연산자는 포인터가 참조하는 곳의 데이터를 가져오겠다는 뜻이다. 
//즉 temp = *a 는 a가 주소인 곳에 있는 값을 가져와(참조) 저장한다. 
//&는 주소 연산자로, &a는 a의 주소값을 가져온다. 

void fn_swap(int *a, int *b);
void new_swap(int *a, int *b);

int main(){
    int a,b;


    printf("정수 두 개를 입력하세요: ");
    scanf("%d %d", &a, &b);
    printf("포인터 주소 %p %p", &a, &b);
    printf("\n");
    

    fn_swap(&a,&b);
    printf("바뀐 정수 : %d, %d", a,b);
    printf("포인터 주소 %p %p", &a, &b);
}

void fn_swap(int *a, int *b){   //포인터형 변수를 인수로 받겠다는 뜻, a의주소와 b의주소를 인수로 받는다
    // a=1, b=4라고 가정
    int temp;
    temp = *a;  //&a에 담겨 있는 값(=1)을 temp로 가져온다(참조). 
    *a = *b;    //&a에 담겨있는 값(=1)을 &b에 담겨있는 값(=4)으로 변경
    *b = temp;  //&b에 담겨있는 값(=4)를 temp값(=1)로 변경

    //여기서 각 변수의 주소값은 변경되지 않았다. 
}




/*
void new_swap(int x, int y) {
    printf("x 의 주소 : %p\n", x);
    int temp = x;
    x = y;
    y = temp;
}
*/
