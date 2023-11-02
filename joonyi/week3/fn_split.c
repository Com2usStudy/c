#include <stdio.h>
#include <stdlib.h>

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
    for (int i = 0; i < length; i++)
	{
		if (*(str + i) == c)
			found_count++;
	}
	found_count++;

    return found_count;
}

char** fn_split(char const* str, char c)
{
	char** splitted;
	int length = get_length(str);
	int found_count = 0;

	// 1. 구분자인 c가 몇 개인지? 그 개수 + 1만큼 2차원 배열의 크기를 정해주자.
	found_count = get_string_count(str, c);

	splitted = (char **) malloc(found_count);

	// 2. 나눠지는 문자열 개수 만큼 또 배열의 크기를 할당해주자.
	int size = 0;
	int string_index = 0;
	for (int i = 0; i < length; i++, size++)
	{
		if (*(str + i) == c)
		{
			splitted[string_index] = (char *)malloc(size + 1);

			size = -1;
			string_index++;
		}
	}
	if (size >= 0)
		splitted[string_index] = (char *)malloc(size + 1);

	// 3. 실제로 2차원 배열에 문자(char) 를 각각 넣어주자.
	string_index = 0;
	int char_index = 0;
	for (int i = 0; i < length; i++)
	{
		if (*(str + i) == c)
		{
			splitted[string_index][char_index] = '\0';
			string_index++;
			char_index = 0;
		}
		else
		{
			splitted[string_index][char_index++] = *(str + i);
		}
	}
	splitted[string_index][char_index] = '\0';

	return splitted;
}

int main(int argc, char *argv[])
{
	char **result;
	printf("받은 문자열 : %s\n자를 문자 기준 : %c\n", argv[1], *argv[2]);
	result = fn_split(argv[1], *argv[2]);

    int string_count = get_string_count(argv[1], *argv[2]);
	for (int i = 0; i < string_count; i++)
	{
		printf("%d번째 문자 : '%s'\n", i, *(result + i));
	}
}