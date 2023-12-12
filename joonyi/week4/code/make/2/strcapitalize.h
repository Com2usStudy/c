#ifndef STRCAPITALIZE_H
#define STRCAPITALIZE_H
#include <stdio.h>

/*
- input) `salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un`
- output) `Salut, Comment Tu Vas ? 42mots Quarante-Deux; Cinquante+Et+Un`
- `char *strcapitalize(char *str)`
*/

/*
* 각 단어의 첫 글자를 대문자로 바꾸는 함수
* 인풋 값과 아웃풋 값을 비교했을 때
* 아마도 ASCII 값에서 알파벳이 아닌 애들을 단어 구분 기호로 삼는것 같아 보임
* +나 -와 같은 기호가 등장해도 다음 영문자를 대문자로 바꿔주는 것을 볼 수 있음.
*/

/*
* 문자열의 길이를 구하는 함수
*/
int get_length(char* str)

/*
* strcapitalize()
* 알파벳이 아닌 모든 기호를 단어 구분 기호로 하여 단어의 첫 글자를 모두 대문자로 바꿔주는 함수
* Abcd 를 ABcd 로 안 바꾸도록 주의.
*/
char* strcapitalize(char* str);
#endif