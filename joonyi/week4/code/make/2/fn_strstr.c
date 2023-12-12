#include <string.h>
#include <stdio.h>

/*
abcde
abz

인자에 NULL 일 경우
*/

char* fn_strstr(const char* string1, const char* string2)
{
	if (string1 == NULL || string2 == NULL) {
		return NULL; // If either of the strings is NULL, return NULL
	}

	int first_index = 0;
	int found_index = 0;
	char* found_ptr = (char*)string1;
	while (*(string1 + first_index) != '\0')
	{
		int second_index = 0;
		int is_found = 1;
		while (*(string2 + second_index) != '\0')
		{
			char first_character = *(string1 + first_index + second_index);
			char second_character = *(string2 + second_index);
			if (first_character != second_character) {
				is_found = 0;
				break;
			}

			second_index++;
		}

		if (is_found)
		{
			found_ptr = (char*)(string1 + first_index);

			return found_ptr;
		}
		first_index++;
	}

	return NULL;

}