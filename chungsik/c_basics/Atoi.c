/*atoi와 똑같이 동작하는 fn_atoi함수를 만드시오*/

#include <stdio.h>
#include <stdlib.h>

int fn_Atoi(const char* str);

int main()
{
	char str1[100] ;
	scanf_s("%s", str1, sizeof(str1));
	int num = fn_Atoi(&str1);

	printf("문자열 \%s\ 를 정수로 변환한 결과 : %d\n", str1, num);

	return 0;
}
/// <summary>
///
/// </summary>
/// <param name="str"></param>
/// <returns></returns>
int fn_Atoi(const char* str) // 문자열 입력 -> 정수 반환
{
	int result = 0; //최종 정수 결과
	int sign = 1; // 숫자가 양수인지 음수인지  (1 : 양수)

	if (*str == '-') // 문자열 첫글자가 '-'(음수부호) sign을 -1로 설정 문자열 포인터('str')한칸 앞으로 이동
	{
		sign = -1;
		str++;
	}

	//문자열에서 숫자 문자('0'에서 '9'사이) 를 찾아 정수로 변환 각 문자열을 처음부터 끝까지 확인 정수로 바꾸어 result에 더한다.
	while (*str >= '0' && *str <= '9') {
		result = result * 10 + (*str - '0');
		str++;
		//문자를 정수로 변환 후 , 한 자리씩 왼쪽으로 옮기면서 정수를 만든다.
	}

	return result * sign; //변환된 정수 sign에 따라 양수 또는 음수 반환 (1 : 양수 -1 : 음수)
}