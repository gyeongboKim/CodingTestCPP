#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <stack>
#include <bitset>
#include <algorithm>


/// <summary>
//세로 0
//가로 1
//n = 1  2x1: 1(0)
//n = 2  2x2 : 2(00, 11)
//n = 3  2x3 : 3(000, 011, 110)
//n = 4  2x4 : 5(0000, 0011, 0110, 1100, 1111)
//n = 5  2x5 : 8(00000, 11110, 11011, 01111, 00011, 00110, 01100, 11000)
//n = 6  2x6 : 13(000000,
//	n = 7  2x7: 21
//	n = 8  2x8 : 34
//	n = 9  2x9 : 55
//	...
//
//	f(1) = 1, f(2) = 2
//	2 x n 크기의 직사각형 채우는 수 : f(n) = f(n - 1) + f(n - 2)
/// </summary>
using namespace std;


void init();
int dp[1001];
int solv(int n) {
	dp[1] = 1;
	dp[2] = 2;

	for(int i = 3; i <= n; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
	}
	return dp[n] % 10007;
	
}





int main()
{
	init();
	
	int n;
	cin >> n;
	cout<<solv(n);
}

void init() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
}



