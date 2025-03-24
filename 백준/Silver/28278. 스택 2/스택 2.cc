#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <istream>
#include <sstream>
/// <summary>
///  스택 구현
/// 1 X: 정수 X를 스택에 넣는다. (1 ≤ X ≤ 100,000)
/// 2 : 스택에 정수가 있다면 맨 위의 정수를 빼고 출력한다.없다면 - 1을 대신 출력한다.
/// 3 : 스택에 들어있는 정수의 개수를 출력한다.
/// 4 : 스택이 비어있으면 1, 아니면 0을 출력한다.
/// 5 : 스택에 정수가 있다면 맨 위의 정수를 출력한다.없다면 - 1을 대신 출력한다.
/// 
/// 첫 째 줄 입력 명령의 수 N
/// 둘째 줄 N개 줄에 명령이 하나씩
/// </summary>

using namespace std;

class Stack {
public:
    vector<int> stackArray;

    Stack() {
        stackArray.reserve(100000); // 미리 메모리 확보 (시간 초과 방지)
    }

    void push(int data) {
        stackArray.push_back(data);
    }

    int pop() {
        if (!stackArray.empty()) {
            int topValue = stackArray.back();
            stackArray.pop_back();
            return topValue;
        }
        return -1;
    }

    int size() {
        return stackArray.size();
    }

    bool empty() {
        return stackArray.empty();
    }

    int top() {
        return empty() ? -1 : stackArray.back();
    }
};

Stack stack;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int commandCount;
    cin >> commandCount;

    for (int i = 0; i < commandCount; i++) {
        int commandOption;
        cin >> commandOption;

        if (commandOption == 1) {
            int dataNumber;
            cin >> dataNumber;
            stack.push(dataNumber);
        }
        else if (commandOption == 2) {
            cout << stack.pop() << '\n';
        }
        else if (commandOption == 3) {
            cout << stack.size() << '\n';
        }
        else if (commandOption == 4) {
            cout << (stack.empty() ? 1 : 0) << '\n';
        }
        else if (commandOption == 5) {
            cout << stack.top() << '\n';
        }
    }

    return 0;
}