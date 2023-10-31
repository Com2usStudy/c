/*atoi�� �Ȱ��� �����ϴ� fn_atoi�Լ��� ����ÿ�*/

#include <stdio.h>
#include <stdlib.h>

int fn_Atoi(const char* str);

int main()
{
	char str1[100] ;
	scanf_s("%s", str1, sizeof(str1));
	int num = fn_Atoi(&str1);

	printf("���ڿ� \%s\ �� ������ ��ȯ�� ��� : %d\n", str1, num);

	return 0;
}
/// <summary>
///
/// </summary>
/// <param name="str"></param>
/// <returns></returns>
int fn_Atoi(const char* str) // ���ڿ� �Է� -> ���� ��ȯ
{
	int result = 0; //���� ���� ���
	int sign = 1; // ���ڰ� ������� ��������  (1 : ���)

	if (*str == '-') // ���ڿ� ù���ڰ� '-'(������ȣ) sign�� -1�� ���� ���ڿ� ������('str')��ĭ ������ �̵�
	{
		sign = -1;
		str++;
	}

	//���ڿ����� ���� ����('0'���� '9'����) �� ã�� ������ ��ȯ �� ���ڿ��� ó������ ������ Ȯ�� ������ �ٲپ� result�� ���Ѵ�.
	while (*str >= '0' && *str <= '9') {
		result = result * 10 + (*str - '0');
		str++;
		//���ڸ� ������ ��ȯ �� , �� �ڸ��� �������� �ű�鼭 ������ �����.
	}

	return result * sign; //��ȯ�� ���� sign�� ���� ��� �Ǵ� ���� ��ȯ (1 : ��� -1 : ����)
}