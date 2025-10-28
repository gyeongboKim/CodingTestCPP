#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <stack>
#include <bitset>
#include <algorithm>


/// <summary>
///N을 1로 만들기 위해 필요한 최소 횟수 = N - 1을 1로 만들기 위한 최소횟수 + 1
///OR 2나 3으로 나누어지면, 나눠지고 남은 몫의 경우의 연산 + 1
/// 
/// </summary>
using namespace std;

pair<int, int> fiboCount[41];

void init();

int cnt = 0;
int dp[1000000];
int makeOne(int n);
int makeOne(int n) {
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + 1;

		if(i%2 == 0)
			dp[i] = min(dp[i], dp[i / 2] + 1);
		if (i % 3 == 0)
			dp[i] = min(dp[i], dp[i / 3] + 1);
	}
	return dp[n];
}

int main()
{
	init();
	int numOfInput;
	cin >> numOfInput;
	cout << makeOne(numOfInput);
}

void init() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
}



