#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
/// <summary>
/// 1. 첫 입력은 명령의수 N
/// 2. 명령이 하나 씩 주어짐.
///     push X
///     pop
///     size
///     empty
///     top
/// 
/// </summary>
/// <returns></returns>
using namespace std;
class Stack {
    int array[10000];
    int tail;
public:
    Stack(){

        tail = -1;
    }
    void push(int data) {
        tail+=1;
        array[tail] = data;

    }
    
    int pop() {
        if (empty() == 1) {
            return -1;
        }
        else if(empty() == 0){
            return array[tail--];
        }
    }

    int size() {
        return tail+1;
    }
    int empty() {
        if (tail == -1) return 1;
        else return 0;
    }
    int top() {
        if (empty() == 1) {
            return -1;
        }
        else if (empty() == 0) {
            return array[tail];
        }
    }
    
};


int main()
{
    string command;
    int testCount = 0;
    int testData = 0;
    scanf("%d", &testCount);
    cin.ignore();
    Stack testStack;
    for (int t = 0; t < testCount; t++) {
        
        int tempNum = 0;

        getline(cin, command);
        if (command.find("push") != string::npos) {
            //stoi : string을 integer로 변환
            //substr : command의 숫자 부분 파싱
            testData = stoi(command.substr(5));

            testStack.push(testData);
        }
        else if (command.find("pop") != string::npos) {
            tempNum = testStack.pop();
            printf("%d\n", tempNum);
        }
        else if (command.find("size") != string::npos) {
            tempNum = testStack.size();
            printf("%d\n", tempNum);
        }
        else if (command.find("empty") != string::npos) {
            tempNum = testStack.empty();
            printf("%d\n", tempNum);
        }
        else if (command.find("top") != string::npos) {
            tempNum = testStack.top();
            printf("%d\n", tempNum);
        }
    }
}

