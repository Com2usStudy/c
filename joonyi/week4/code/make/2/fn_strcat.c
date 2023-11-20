#include <stdio.h>
#include <string.h>

char* fn_strcat(char* string1, const char* string2)
{
	int first_index = 0;
	while (*(string1 + first_index) != '\0')
	{
		first_index++;
	}

	int second_index = 0;
	while (*(string2 + second_index) != '\0')
	{
		*(string1 + first_index + second_index) = string2[second_index];

		second_index++;
	}

	*(string1 + first_index + second_index) = '\0';

	return string1;
}