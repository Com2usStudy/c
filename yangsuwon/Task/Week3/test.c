
#include <stdio.h>
int atoi_fn(const char *str) {
    int result = 0;
    int sign = 1;
    int i = 0;

    // 공백 문자 건너뛰기
    while (str[i] == ' ') {
        i++;
    }

    // 부호 처리
    if (str[i] == '-' || str[i] == '+') {
        sign = (str[i++] == '-') ? -1 : 1;
    }

    // 숫자 변환
    while (str[i] >= '0' && str[i] <= '9') {
        result = (result * 10) + (str[i++] - '0');
    }

    return sign * result;
}
int main() {
    const char *numStr = "12345";
    int num = atoi_fn(numStr);

    printf("변환된 정수: %d\n", num);

    return 0;
}
