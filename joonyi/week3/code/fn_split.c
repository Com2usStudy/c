#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 문자열 길이 구하는 함수
int get_length(char const* str)
{
	int length = 0;
	while (*(str + length) != '\0')
		length++;

	return length;
}

int get_string_count(char const* str, char c)
{
    int length = get_length(str);
    int found_count = 0;

	bool on_counting = 0;
	for (int i = 0; i < length; i++)
	{
		if (*(str + i) == c)
			on_counting = 0;
		else
		{
			if (!on_counting)
				found_count++;
			on_counting = 1;
		}
	}

    return found_count;
}

char** fn_split(char const* str, char c)
{
	char** splitted;

	int string_count = get_string_count(str, c);
	splitted = malloc(sizeof(char*) * string_count);

	if (splitted == NULL)
		return NULL;

	bool on_counting = 0;
	int string_length = 0;
	int string_index = 0;
	int original_length = get_length(str);
	for (int i = 0; i < original_length; i++)
	{
		if (*(str + i) == c)
		{
			// malloc 이 NULL 이면?
			splitted[string_index] = malloc(sizeof(char) * (string_length + 1)); // '\0' 들어갈 공간까지 확보하자.

			if (splitted[string_index] == NULL)
			{
				for (int j = string_index - 1; j >= 0; j--)
					free(splitted[j]);
				return NULL;
			}

			string_index += 1;
			on_counting = 0;
			string_length = 0;
		}
		else
		{
			string_length++;
			on_counting = 1;
		}
	}

	bool on_writing = 0;
	string_index = 0;
	int char_index = 0;
	for (int i = 0; i < original_length; i++)
	{
		if (*(str + i) == c)
		{
			if (on_writing)
				*(splitted[string_index++] + char_index) = '\0';
			on_writing = 0;
			char_index = 0;
		}
		else
		{
			*(splitted[string_index] + char_index++) = *(str + i);
			on_writing = 1;
		}
	}

	return splitted;
}

int main(int argc, char *argv[])
{
	char **result;

	printf("%d\n", get_string_count(argv[1], *argv[2]));

	result = fn_split(argv[1], *argv[2]);

    int string_count = get_string_count(argv[1], *argv[2]);
	if (result == NULL)
		return 0;
	for (int i = 0; i < string_count; i++)
	{
		printf("%d번째 문자 : '%s'\n", i, *(result + i));
	}
}

// aasdfasdfqweraaqweraqwera a
// sdf, sdfqwer, qwer, qwer