#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char *my_strdup(const char *s) {
    if (s == NULL) {
        return NULL;  // 입력 문자열이 NULL이면 NULL을 반환
    }

    size_t len = strlen(s) + 1;  // 마지막에 '\0'까지 계산한 길이
    char *copy = (char *)malloc(len);  // 메모리 할당

    for(int i = 0; i < len; i++) {
        copy[i] = s[i];
    }

    return copy;  // 복제된 문자열의 포인터 반환
}

int main() {
    const char *original = "Hello, World!";
    char *copy = my_strdup(original);

        printf("Original: %s\n", original);
        printf("Copy: %s\n", copy);

        // 메모리 해제
        free(copy);
   

    return 0;
}
