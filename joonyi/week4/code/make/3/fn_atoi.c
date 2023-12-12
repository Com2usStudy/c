// fn_atoi 만들기
#include <stdio.h>
#include <stdbool.h>

int min_value = -2147483648;
int max_value = 2147483647;

/**
* 문자열의 길이를 구하는 함수
*/
int get_length(const char* string)
{
	int length = 0;
	while (*(string + length) != '\0')
	{
		length++;
	}

	return length;
}

/**
* 정수 값 [0-9] 가 들어있는 문자를 정수로 리턴하는 함수.
* 값이 정수가 아닌 나머지 문자가 들어올 경우 예기치 못한 동작.
*/
int get_numeric(char* digit)
{
	return *(digit)-'0';
}

/**
* 숫자인지 확인하는 함수
*/
bool is_numeric(char *c)
{
	return *c >= 48 && *c <= 57;
}

/**
* 양/음수 구분 기호 + or - 인지 확인하는 함수
*/
bool is_plus_or_minus(char *c)
{
	return *c == 43 || *c == 45;
}

/**
* 정수로 읽을 첫번째 문자로서 허용되는지 확인하는 함수
* 허용되는 문자 : [0-9, -, +]
*/
bool is_permitted(char* c)
{
	return is_numeric(c) || is_plus_or_minus(c);
}

/**
* 문자를 받아 정수 자리에 0-9 까지의 값을 가지고 있는 문자를 정수형태로 추가하는 함수
*/
int* add_digit(int* result, char* digit)
{
	*result *= 10;
	*result += get_numeric(digit);

	return result;
}



/**
* now의 마지막 자리에 정수 값을 넣어도 int 의 최대, 최소값을 초과하진 않는지 확인하는 함수
* int의 최대값과 최소값은 각각 2147483647, -2147483648
* 
* (example)
* 양수라고 가정하고 now가 214748363 에는 아무 정수 1 digit이라도 추가가 가능하다.
* 그런데 현재 now가 214748364 일 경우 digit은 7까지만 추가가 가능하다. 
* 현재 now가 214748365 일 경우 아무런 digit 도 추가할 수 없다.
*/
bool is_appendable(int* now, int* digit, bool* is_negative)
{
	bool result = 0;

	// 음수일 경우 마지막 digit 을 8까지 허용한다.
	int last_digit = 7;
	if (!is_negative)
		last_digit = 8;

	if (*now < max_value / 10)
		result = 1;
	else if (*now == max_value / 10)
	{
		if (*digit <= last_digit)
			result = 1;
	}

	return result;
}

/**
* 과제에서 제시한 atoi() 와 똑같이 동작하는 함수
*/
int fn_atoi(const char* string)
{
	int length = get_length(string);
	bool is_started = 0;
	bool is_negative = 0;
	bool is_min_or_max = 0;
	int result = 0;

	for (int i = 0; i < length; i++)
	{
		char c = *(string + i);
		int numeric_value = get_numeric(&c);

		if (is_started)
		{
			if (is_numeric(&c))
			{
				if (is_appendable(&result, &numeric_value, &is_negative))
					add_digit(&result, &c);
				else
				{
					is_min_or_max = 1;
					break;
				}
			}
			else
				break;
		}
		else
		{
			if (is_permitted(&c))
			{
				is_started = 1;
				if (c == '-')
					is_negative = 1;
				if (is_numeric(&c))
					add_digit(&result, &c);
			}
			else if (c == ' ')
				continue;
			else
				break;
		}
	}

	if (is_negative)
		result *= -1;

	if (is_min_or_max)
	{
		result = max_value;
		if (is_negative)
			result = min_value;
	}

	return result;
}

int main()
{
	char a[] = "1234";			// 1234
	char b[] = "-1234";			// -1234
	char c[] = "- 1234";		// 0
	char d[] = "1234.10";		// 1234
	char e[] = "1234.99";		// 1234
	char f[] = "-123    4";		// -123
	char g[] = "123    4";		// 123
	char h[] = "    123 4";		// 123
	char i[] = "1234    a";		// 1234
	char j[] = " e1234";		// 0
	char k[] = " e+1234";		// 0
	char l[] = "+1234";			// 1234
	char m[] = " +1234";		// 1234
	char n[] = " + 1234";		// 0
	char o[] = "+9999999999";	// 2147483647
	char p[] = "-9999999999";	// -2147483648
	char q[] = "--1234";		// 0
	char r[] = "++1234";		// 0
	char s[] = "+-1234";		// 0
	char t[] = "-+1234";		// 0
	char u[] = "=1234";			// 0
	char v[] = "01234";			// 1234
	char w[] = "0     1234";	// 0

	printf("%d\n", fn_atoi(a));
	printf("%d\n", fn_atoi(b));
	printf("%d\n", fn_atoi(c));
	printf("%d\n", fn_atoi(d));
	printf("%d\n", fn_atoi(e));
	printf("%d\n", fn_atoi(f));
	printf("%d\n", fn_atoi(g));
	printf("%d\n", fn_atoi(h));
	printf("%d\n", fn_atoi(i));
	printf("%d\n", fn_atoi(j));
	printf("%d\n", fn_atoi(k));
	printf("%d\n", fn_atoi(l));
	printf("%d\n", fn_atoi(m));
	printf("%d\n", fn_atoi(n));
	printf("%d\n", fn_atoi(o));
	printf("%d\n", fn_atoi(p));
	printf("%d\n", fn_atoi(q));
	printf("%d\n", fn_atoi(r));
	printf("%d\n", fn_atoi(s));
	printf("%d\n", fn_atoi(t));
	printf("%d\n", fn_atoi(u));
	printf("%d\n", fn_atoi(v));
	printf("%d\n", fn_atoi(w));
}