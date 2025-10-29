#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <stack>
#include <bitset>
#include <algorithm>


/// <summary>
//1=> 1개 			1														자신
//2 = > 2개 			1 1, 2													1 구성식에 1추가, 자신
//3 = > 4개 			1 1 1 / 2 1, 1 2 / 3									2 구성식에 1추가, 1 구성식에 2추가, 자신
//4 = > 7개 			1111 / 112, 121, 211, 22 / 13, 31						3 구성식에 1추가, 2 구성식에 2추가, 1 구성식에 3추가
//5 = > 13 개 		11111, 1121, 1211, 2111, 221, 131, 311 / 1112, 212, 122, 32 / 113, 23	4 구성식에 1추가, 3 구성식에 2추가, 2 구성식에 3추가
//6 = > 24
//7 = > 44
/// </summary>
using namespace std;


void init();
int dp[12];

void repeatInput(int n) {
	for (int i = 0; i < n; i++) {
		int testCase;
		cin >> testCase;
		for (int index = 1; index <= testCase; index++) {
			if (index == 1) {
				dp[index] = 1;
			}
			else if (index == 2) {
				dp[index] = 2;
			}
			else if (index == 3) {
				dp[index] = 4;
			} 
			else {
				dp[index] = dp[index - 1] + dp[index - 2] + dp[index - 3];
			}
		}
		cout << dp[testCase] << '\n';
			

	}
}




int main()
{
	init();
	
	int countOfTest;
	cin >> countOfTest;
	repeatInput(countOfTest);
}

void init() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
}



