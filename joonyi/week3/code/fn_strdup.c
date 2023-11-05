#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* fn_strdup(const char* string)
{
	char* str = (char *) malloc(sizeof(string) + 1);

	if (str == NULL)
		return NULL;

	strcpy(str, string);

	return str;
}

int main(int argc, char* argv[])
{
	char* copied;

	copied = fn_strdup(argv[1]);

	printf("복사해버림 : %s\n", copied);
}