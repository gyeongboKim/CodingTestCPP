#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <sstream>
#include <stack>

/// <summary>
///
/// 
/// </summary>

using namespace std;

bool isPalindrome(int value);
void repeatInput();
string DigitsString(int number);



void repeatInput() {
	while (true) {
		int value;
		cin >> value;
		
		if (value == 0) {
			break;
		}

		if (isPalindrome(value))
			cout << "yes" << "\n";
		else
			cout << "no" << "\n";
	}
}

string DigitsString(int number) {
	std::string numStr = std::to_string(number);
	return numStr;
}


bool isPalindrome(int value) {
	stack<int> st1;

	
	string strValue = DigitsString(value);
	int len = strValue.length();
	if (stoi(strValue.substr(0, 1)) == 0) 
		return false;
	
	int pivot;
		
	if (len % 2 == 0) {
		pivot = len / 2;
	}
	else {
		pivot = len / 2 + 1;
	}

	for (int index = 0; index < len/2 ; index++) {
		st1.push(stoi(strValue.substr(index, 1)));
	}
	for (int index = pivot ; index < len; index++) {
		if (st1.top() == stoi(strValue.substr(index, 1)))
			st1.pop();
		else
			return false;
	}

	return st1.empty();
}

int main()
{
	
	repeatInput();
}
