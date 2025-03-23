#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include <vector>
#include <stdio.h>


/// <summary>
/// stack에 1 부터 N 까지 오름차순으로 존재할 때
/// pop, push를 이용하여 
/// 임의의 수열을 만들 수 있는지 
/// (수열을 만들기 위해 pop push 연산은 N*2배 실행됨.)
/// 
/// 입력 첫줄 n
/// n 번 입력
/// 첫 testNumber 
///		testNumber 까지 push 후 pop
/// 두 번째 testNumber 이후
///		1.현재 testNumber가 이전 testNumber 보다 큰 경우
///			testNumber 까지 push 후 pop
///		2. 현재 testNumber가 스택 top()과 값이 같은 경우
///			pop 가능
///		3. 나머지의 경우는 false
/// 각 push 연산과 pop 연산에 대해 +, -를 저장.
///			
/// </summary>

using namespace std;


int main()
{
	
	stack<int> ascendingNumber;
	bool isPossible = true;
	int testCount = 0;
	int firstTestNumber = 0;
	int currentTestNumber = 0;
	int previousTestNumber = 0;
	scanf("%d", &testCount);
	cin.ignore();
	vector<char> stackOperation;
	vector<char>::iterator operationIterator;
	scanf("%d", &firstTestNumber);
	cin.ignore();
	for (int pushNumber = 1; pushNumber <= firstTestNumber; pushNumber++) {
		ascendingNumber.push(pushNumber);
		stackOperation.push_back('+');
	}
	previousTestNumber = ascendingNumber.top();
	ascendingNumber.pop();
	stackOperation.push_back('-');
	

	for (int t = 1; t < testCount; t++) {
		scanf("%d", &currentTestNumber);
		//이전 testNumber보다 큰 경우
		if (currentTestNumber > previousTestNumber) {
			for (int pushNumber = previousTestNumber+1; pushNumber <= currentTestNumber;pushNumber++) {
				ascendingNumber.push(pushNumber);
				stackOperation.push_back('+');
			}
			previousTestNumber = ascendingNumber.top();
			ascendingNumber.pop();
			stackOperation.push_back('-');
		}
		//현재 testNumber가  top한 값과 같은 경우
		else if(currentTestNumber == ascendingNumber.top()){
			
			ascendingNumber.pop();
			stackOperation.push_back('-');
		}
		//나머지의 경우
		else {
			isPossible = false;
		}	
	}
	if (isPossible) {
		for (operationIterator = stackOperation.begin(); operationIterator != stackOperation.end(); ++operationIterator) {
			printf("%c\n", *operationIterator);
		}
	}
	else {
		printf("NO");
	}
}

