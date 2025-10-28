#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <stack>
#include <bitset>
#include <algorithm>


/// <summary>
///
/// 
/// </summary>
using namespace std;

pair<int, int> fiboCount[41];

void init();
void repeatInput(int a);

pair<int, int> fibo(int n);

pair<int, int> fibo(int n) {
	if (n == 0) {
		fiboCount[0].first = 1;
		fiboCount[0].second = 0;
		return fiboCount[0];
	}
	else if (n == 1) {
		//printf("1");
		fiboCount[1].first = 0;
		fiboCount[1].second = 1;
		return fiboCount[1];
	}
	else if (fiboCount[n].first ) {
		return fiboCount[n];
	}
	else {
		return fiboCount[n] = make_pair(fibo(n - 1).first + fibo(n - 2).first, fibo(n - 1).second + fibo(n - 2).second);
	}
}

int main()
{
	init();
	int numOfInput;
	cin >> numOfInput;
	repeatInput(numOfInput);
	
	

}

void init() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
}




void repeatInput(int a) {
	
	for (int i = 0; i < a; ++i) {
		int testNumber;
		cin >> testNumber;
		fibo(testNumber);
		cout << fiboCount[testNumber].first << " " << fiboCount[testNumber].second << "\n";
		
	}
}