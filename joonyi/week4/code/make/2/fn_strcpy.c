#include <stdio.h>
#include <string.h>

int get_length(char* string)
{
	int index = 0;
	while (*(string + index) != '\0')
	{
		index++;
	}

	return index + 1;
}

char* fn_strcpy(char* target, char* origin)
{
	int length = get_length(origin);

	for (int i = 0; i < length; i++)
	{
		*(target + i) = *(origin + i);
	}

	return target;
}