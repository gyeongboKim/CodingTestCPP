#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

/// <summary>
/// 
/// push X: 정수 X를 큐에 넣는 연산이다.
/// pop: 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다.만약 큐에 들어있는 정수가 없는 경우에는 - 1을 출력한다.
/// size : 큐에 들어있는 정수의 개수를 출력한다.
/// empty : 큐가 비어있으면 1, 아니면 0을 출력한다.
/// front : 큐의 가장 앞에 있는 정수를 출력한다.만약 큐에 들어있는 정수가 없는 경우에는 - 1을 출력한다.
/// back : 큐의 가장 뒤에 있는 정수를 출력한다.만약 큐에 들어있는 정수가 없는 경우에는 - 1을 출력한다.
/// 
/// </summary>


#define QUEUELENGTH 10001

using namespace std;

class queue 
{
private:
	int queueArray[QUEUELENGTH];
	int frontCursor = 0;
	int rearCursor = 0;
	int queueSize;
	
public:
	void push(int data) 
	{
		//cout << "push finished" << "\n";
		queueArray[rearCursor++] = data;
	}
	int pop()
	{
		if (empty()) return -1;
		else return queueArray[frontCursor++];
	}
	int size()
	{
		return rearCursor - frontCursor;
	}
	int empty() 
	{
		//비어 있는 경우 frontCursor와 rearCursor가 같음
		if (frontCursor == rearCursor)
		{
			return 1;
		}
		else return 0;
	}
	int front() {
		if (empty()) return -1;
		else return queueArray[frontCursor];
	}
	int back() {
		if (empty()) return -1;
		else return queueArray[rearCursor - 1];
	}
	
};

int main()
{
	queue testQueue;
	string sentence;
	int testCount = 0;
	cin >> testCount;

	string command;
	string data;

	cin.ignore();

	for (int testIndex = 0; testIndex < testCount; ++testIndex) {
		
		getline(cin, sentence);
		int position = sentence.find(" ");
		if (position != string::npos) {
			//cout << "find successed" << "\n";
			command = sentence.substr(0, position);
			data = sentence.substr(position + 1);
			testQueue.push(stoi(data));
		}
		else {
			command = sentence;
			//cout << "command is " << sentence <<"\n";
			if (command == "pop") {
				cout<<testQueue.pop()<<"\n";
			}
			else if (command == "size") {
				cout<<testQueue.size()<<"\n";
			}
			else if (command == "empty") {
				cout<<testQueue.empty()<<"\n";
			}
			else if (command == "front") {
				cout<<testQueue.front()<<"\n";
			}
			else if (command == "back") {
				cout << testQueue.back() << "\n";
			}
		}
		
		
		//cout << position<<"\n";
		//cout << command << "\n";
		//cout << data << "\n";
	}
				
}