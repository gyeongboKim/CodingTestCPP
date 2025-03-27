#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>

/// <summary>
///  입력으로 들어오는 문자열에는 영문 소문자(a, b, ..., z)로만 구성되어있다고 가정
///  a에는 1, b에는 2, c에는 3, ..., z에는 26으로 고유한 번호를 부여
///  결과적으로 하나의 문자열을 수열로 변환할 수 있음. 예를 들어 'abba'는 1221이 됨.
/// 
/// 해시값을 계산하기 위해 문자열 혹은 수열을 하나의 정수로 치환함
/// 예로 간단하게는 수열의 값을 모두 더한 값과,
/// 해시함수는 유한한 범위의 출력을 가져야 하기 때문에 적당히 큰 수 M으로 나눈다 가정
/// 수식은 H = i=0 ~ i-1 ai mod M 
/// 
/// 위에서 정의한 해시함수는 알파벳 순서만 바꿔도 충돌이 일어나기 때문에 나쁜 해시 함수임.
/// ex) aab baa 두 문자열은 공통된 합을 가져 충돌이 일어남.
/// 
/// 개선 : 수열의 각 항마다 고유한 게수를 부여하는 아이디어
/// H = i-0 ~ i - 1 ai*ri mod M
/// 
/// r 과 M은 서로소인 숫자로 정하는 것이 일반적
/// r = 31	M = 1234567891
/// 
/// 입력 첫 줄에는 문자열의 길이 L
/// 둘째 줄에는 영문 소문자로 이루어진 문자열
/// 입력으로 주어지는 문자열은 모두 알파벳 소문자로 구성
/// 
/// 주어진 해시함수와 입력으로 주어진 문자열을 사용해 계산한 해시 값을 정수로 출력
/// 
/// </summary>

using namespace std;

int main() 
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int senteceLength = 0;
	long long sum = 0;
	double ratio = 31;
	long long modularNumber = 1234567891;
	cin >> senteceLength;
	char sentence[50];

	for (int index = 0; index < senteceLength; index++) {
		cin >> sentence[index];
		sum += (sentence[index] - '`')*pow(ratio, index);
	}
	cout << sum % modularNumber<< '\n';

	
	
}
 
