#include <stdio.h>
#include <string.h>

/*
[입력]
aaaaa aaa aa aaaa
*/

void swap(char* left, char* right)
{
	char temp[100];
	printf("swp v1, v2 : %s  : %s\n", left, right);

	strcpy(temp, left);
	strcpy(left, right);
	strcpy(right, temp);
}

void sort(char arr[100][100], int length)
{
	char temp[100];
	char* temp_ptr = temp;

	for (int i = 0; i < length - 1; i++)
	{
		for (int j = 0; j < length - i - 1; j++)
		{
			if (strcmp(*(arr + j), *(arr + j + 1)) < 0)
			{
				char temp[100];

				strcpy(temp, *(arr + j));
				strcpy(*(arr + j), *(arr + j + 1));
				strcpy(*(arr + j + 1), temp);
			}
		}
	}
}


int main(int argc, char* argv[])
{
	argv++; // 인자 0번째는 불필요한 인자(프로그램의 실행 경로)가 들어있으므로 생략한다.
	argc--; // 마찬가지로 개수도 조절해준다.
	printf("인자 개수 %d\n", argc);

	char sorted[100][100];
	printf("===========오리지날 출력 ========\n");
	for (int i = 0; i < argc; i++)
	{
		printf("%s\n", argv[i]);
		strcpy(sorted[i], argv[i]);
	}

	sort(sorted, argc);

	char temp[100];

	printf("===========정렬 출력========\n");
	for (int i = 0; i < argc; i++)
	{
		printf("출 : %s\n", sorted[i]);
		//printf("ss : %s\n", sorted + i);
	}

}