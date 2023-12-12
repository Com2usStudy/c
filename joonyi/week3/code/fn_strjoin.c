#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int get_length(const char* str)
{
    int length = 0;
    while (*(str + length) != '\0')
        length++;

    return length;
}

char* fn_strjoin(const char* left, const char* right)
{
	int left_length = get_length(left);
	int right_length = get_length(right);

	char* result = (char *) malloc(left_length + right_length + 1);

	if (result == NULL)
		return NULL;

	for (int i = 0; i < left_length; i++)
		*(result + i) = *(left + i);
	for (int i = left_length; i < (left_length + right_length); i++)
		*(result + i) = *(right + i - left_length);
	*(result + left_length + right_length) = '\0';

	return result;
}


int main(int argc, char* argv[])
{
	char *result;

	result = fn_strjoin(argv[1], argv[2]);

	printf("joined! : %s\n", result);
}