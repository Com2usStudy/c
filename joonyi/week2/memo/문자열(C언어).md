# 본문

[[C언어]]에서 문자 1개를 나타내는 [[char(C언어)]] 자료형은 있지만 `여러 개의 문자` 를 나타내는 `문자열` 을 저장하는 자료형은 없다. 따라서 `C언어` 에서 문자열을 저장하기 위해선 `char` 형 배열을 사용한다.

## 문자열의 특성

`C언어` 에서 문자열은 여러 개의 `char` 데이터로 구성된다. 그리고 연속된 `char` 데이터의 끝을 알리기 위해 마지막에 `\0(널 문자)` 를 꼭 포함한다.

## 문자열을 선언하려면

`C언어` 에서 문자열을 변수에 저장하려면 일반적으로 `char`배열 형식으로 저장한다.

```c
char string_a[5] = "abcd"; // 문자열의 길이를 알 때
char string_b[] = "I don't know how long it is."; // 문자열의 길이를 모를 때
```