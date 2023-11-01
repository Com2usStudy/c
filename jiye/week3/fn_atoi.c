#include <stdio.h>

//문자열을 int형으로 변환하는 함수. 
//숫자로 바꿀 수 없는 문자가 나오면 변환을 중지하고 이미 변환된 값만 반환
//만약 아무것도 변환하지 못하면 0 반환
int fn_atoi(const char *string);

int main(){
    char string[12];
    printf("숫자를 입력하세요: ");
    fgets(string, 10, stdin);

    int i = fn_atoi(string);
    printf("char로 받은 숫자를 int로 : %d\n", i);
}

int fn_atoi(const char *string){
    int result = 0;     //만약 추후에 아무것도 변환하지 못하면 그대로 0 반환
    int flag = 1;   //음수 부호 처리를 한번만 하기 위한 flag

    for(const char* ptr = string; *ptr!='\0'; ptr++){
        if(flag && *string == '-') {
            flag = 0;
            continue;     //음수 부호는 나중에 처리
        }

        if(*ptr >= '0' && *ptr <= '9'){     //입력받은 것이 숫자일 때만 변환
            result = result * 10 + (*ptr - '0');    //문자열로 표현된 숫자는 아스키코드표에 연속적으로 존재하므로
                                                    //0에 해당하는 아스키코드값을 빼주면 원래 숫자가 나온다. 
                                                    //포인터가 한칸 이동할 때마다 한자릿수씩 증가하므로
                                                    //직전 값에 10을 곱하고 1의자릿수를 구해 더해준다.  
        }
        else break;     //숫자가 아닌 것이 나오면 변환 중지
    }

    if(*string == '-'){    //만약 입력받은 것의 맨 처음에 음수 부호가 붙어있다면 음수 부호 붙여줌
        result *= -1;
    }
    return result;
}
