#include <stdio.h>

int fn_strcmp(const char *string1, const char *string2);

int main(void) {
    char *string1 = "comparet";
    char *string2 = "compares";

    int result = fn_strcmp(string1, string2);
    printf("%d\n", result);

    if (result == 0) {
        printf("Equal\n");
    } else if (result < 0) {
        printf("The second string has a larger ASKII code value.\n");
    } else {
        printf("The first string has a larger ASKII code value.\n");
    }
    
    return 0;
}

int fn_strcmp(const char *string1, const char *string2) {
    while (*string1 && *string2 && *string1 == *string2) {
        string1++;
        string2++;
    }
    // Calculate in ASKII code
    return *string1 - *string2;
}
