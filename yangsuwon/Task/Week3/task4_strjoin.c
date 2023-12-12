#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// chat gpt의 도움을 받음

char *fn_strjoin(const char *s1, const char *s2) {
    if (s1 == NULL || s2 == NULL) {
        return NULL;  // 입력 문자열 중 하나라도 NULL인 경우 NULL을 반환
    }

    // 두 문자열의 길이 계산
    size_t len1 = strlen(s1);
    size_t len2 = strlen(s2);

    // 새로운 문자열을 저장할 메모리 할당 (길이: len1 + len2 + 1)
    char *result = (char *)malloc(len1 + len2 + 1);

    if (result != NULL) {
        // 첫 번째 문자열 복사
        strcpy(result, s1);
        // 두 번째 문자열 이어붙이기
        strcat(result, s2);
    }

    return result;  // 합쳐진 문자열의 포인터 반환
}

int main() {
    const char *s1 = "Hello, ";
    const char *s2 = "World!";
    
    char *joined = fn_strjoin(s1, s2);
    
    if (joined != NULL) {
        printf("Joined String: %s\n", joined);
        free(joined);  // 메모리 해제
    } else {
        fprintf(stderr, "Memory allocation failed.\n");
    }

    return 0;
}