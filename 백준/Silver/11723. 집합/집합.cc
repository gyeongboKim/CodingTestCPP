#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <sstream>
#include <stack>
#include <bitset>
/// <summary>
///
/// 
/// </summary>
using namespace std;

void repeatInput(int a);
void bitwiseOperator(string command, int bit = 0);
void init();

const int MAX_BiT_SIZE = 20;
bitset<MAX_BiT_SIZE> myBitset;

int main()
{
	init();
	myBitset.reset();
	int numberOfInput;
	cin >> numberOfInput;
	repeatInput(numberOfInput);
}

void init() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
}


void repeatInput(int a) {
	for (int i = 0; i < a; ++i) {
		string command;
		cin >> command;
		if (command == "add"
			|| command == "remove"
			|| command == "check"
			|| command == "toggle")
		{
			int value;
			cin >> value;
			bitwiseOperator(command, value - 1);
		}
		else if(command == "all" || command == "empty")
		{
			bitwiseOperator(command);
		}
		

	}
}

void bitwiseOperator(string command, int bit) {
	
	bool exists = myBitset.test(bit);

	if (command == "add") {
		if (exists) { return; }
		myBitset.set(bit);
		return;
	}
	if (command == "remove") {
		if (!exists) { return; }
		myBitset.reset(bit);
		return;
	}
	if (command == "check") {
		if (exists) {
			cout << 1 << "\n";
			return;
		}
		else
		{
			cout << 0 << "\n";
			return;
		}
	}
	if (command == "toggle") {
		myBitset.flip(bit);
		return;
	}
	if (command == "all") {
		//add all
		myBitset.set();
		return;
	}
	if (command == "empty") {
		//remove all
		myBitset.reset();
		return;
	}
}
