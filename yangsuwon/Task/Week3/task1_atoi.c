#include <stdio.h>
#include <stdlib.h>
int atoi_fn(const char *str) {
    int result = 0;
    int sign = 1;
    int i = 0;

    // 공백문자열이면 인덱스 ++
    while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
    {
        i++;
    }

    // +/- 문자가 있으면 +는 1로 -는 -1로 변환
    if(str[i] == '+' || str[i] == '-'){
        sign = (str[i] == '-')? -1 : 1;
    }

    // 숫자라면 result에 추가 뒤에 추가적이 수가 있다면 
    // 자리수를 늘린다음에 숫자를 추가한다. 
    while ( str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + (str[i++] - '0');
    }
    
    return sign * result;
    

}

void main() {
      int i;
  char szInput[10] = "123";

  i = atoi_fn(szInput);
  printf("The value entered is %d. The double is %d.\n", i, i * 2);
}