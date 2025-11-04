#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <stack>
#include <bitset>
#include <algorithm>


/// <summary>
//  입력  5 4 3 2 1
//  2 4 : (5 + 4 + 3 + 2) - (5) => dp[4] - dp[1]
/// </summary>
using namespace std;


void init();


int number[1000001];
int dpSum[1000001];
void repeatInput(int numberCount, int testCount) {
	cin.ignore();
	//1. 공백 포함한 string 입력받기
	string input;
	getline(cin, input);
	// 문자열을 스트림화
	stringstream ss(input);
	// 공백 분리 결과를 저장할 배열
	vector<string> results;

	string token;
	//스트림을 한줄 씩 읽어, 공백 단위로 분리 후 결과 배열에 저장
	while (getline(ss, token, ' ')) {
		results.push_back(token);
	}
	//3. 자른 string int로 변환
	for(int i = 0; i < results.size(); i++) {
		number[i] = stoi(results[i]);
	}
	// 3 - 1. dpSum 배열에 누적합 저장
	dpSum[1] = number[0];
	dpSum[2] = dpSum[1] + number[1];
	for(int i = 2; i <= numberCount; i++) {
		dpSum[i] = dpSum[i - 1] + number[i - 1];
	}
	//4. start~end 까지 합 구하기를 테스트 케이스 수만큼 반복
	for (int i = 0; i < testCount; i++) {
		int start, end;
		cin >> start >> end;
		cout << dpSum[end] - dpSum[start - 1] << "\n";
	
		
	}
}




int main()
{
	init();
	
	int numberCount, testCount;
	cin >> numberCount >> testCount;
	repeatInput(numberCount, testCount);
}

void init() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
}




