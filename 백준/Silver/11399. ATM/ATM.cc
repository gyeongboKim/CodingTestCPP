#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <list>
#include <sstream>
#include <stack>
#include <bitset>
#include <unordered_map>
/// <summary>
///
/// 
/// </summary>
using namespace std;

void init();

class Person {
public:
	int numberOfPeople;
	list<int> time;

	void addTime(int t) {
		time.push_back(t);
	}
	void sortTime() {
		time.sort();
	}
	void printTime() {
		for (auto iter = time.begin(); iter != time.end(); ++iter) {
			cout << *iter << ' ';
		}
		cout << '\n';
	}
	void minOfSumTime(){
	
		int sum = 0;
		int min = 0;
		for (auto iter = time.begin(); iter != time.end(); ++iter) {
			sum = sum + *iter;
			min = min + sum;
		}
		cout << min << '\n';
	}
	//parseInt
	void parseInt(string str) {
		stringstream ss(str);
		int number;
		while (ss >> number) {
			addTime(number);
		}
	}


	
};

int main()
{
	init();
	
	Person person;

	string str;
	int numberOfPeople;

	cin >> numberOfPeople;
	person.numberOfPeople = numberOfPeople;

	cin.ignore();
	getline(cin, str);
	person.parseInt(str);

	person.sortTime();
	person.minOfSumTime();
}

void init() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
}




//void repeatInput(int a, list<int> time) {
//	
//	for (int i = 0; i < a; ++i) {
//		string neverHeardName;
//		cin >> neverHeardName;
//	
//	}
//}