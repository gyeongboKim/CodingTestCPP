#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <istream>
#include <sstream>
/// <summary>
///  1. 첫 줄은 편집기에 입력되는 문자열 입력
///  2. 둘째 줄은 입력할 명령어의 개수를 나타내는 정수가 주어짐
///  3. 셋째 줄 부터 M개의 줄에 걸쳐 입력할 명령어가 순서대로 주어짐.
///     L 커서를 왼쪽으로 한 칸 이동
///         Left에서 pop 후 Right에 push
///     D 커서를 오른쪽으로 한 칸 이동
///         Right에서 pop 후 Left에 push
///     B 커서 왼쪽에 있는 문자를 삭제함
///         Left에서 pop
///     P $   $라는 문자를 커서 왼쪽에 추가
///         Left에 $ push
/// </summary>

using namespace std;

vector<char> cursorLeft;
vector<char> cursorRight;

void executeCursorAction(string command) {

    char commandFront = command.front();
    char commandBack = command.back();
    switch (commandFront) {
    case 'L':
        //커서 왼쪽으로 한 칸 이동
        //커서가 맨 앞일 경우 무시 (커서 왼쪽으로 문자열이 있을 경우에만 실행)
        if (!cursorLeft.empty()) {
            cursorRight.push_back(cursorLeft.back());
            cursorLeft.pop_back();
        }
        break;
    case 'D':
        //커서 오른쪽으로 한 칸 이동
        //커서가 맨 뒤일 경우 무시 (커서 오른쪽으로 문자열이 있을 경우에만 실행)
        if (!cursorRight.empty()) {
            cursorLeft.push_back(cursorRight.back());
            cursorRight.pop_back();
        }
        break;
    case 'B':
        //커서 왼쪽의 문자를 삭제
        //커서가 맨 앞일 경우 무시 (커서 왼쪽으로 문자열이 있을 경우에만 실행)
        if (!cursorLeft.empty()) {
            cursorLeft.pop_back();
        }
        break;
    case 'P':
        //커서 왼쪽에 문자 추가
        cursorLeft.push_back(commandBack);
        break;
    default:
        break;
    }
}
//  yxabc

int main()
{
    string sentence;
    int commandCount = 0;
    string command;
    
    // 첫 줄 : 문장 입력
    getline(cin, sentence);
    //cin.ignore();
    // 문장을 커서의 왼쪽에 전부 push
    for (char sentenceCharacter : sentence) {
        cursorLeft.push_back(sentenceCharacter);
    }

    // 둘째 줄 : 명령어의 개수 입력
    cin >> commandCount;
    cin.ignore();

    // 셋째 줄 ~ command 입력
    for (int commandIndex = 0; commandIndex < commandCount; commandIndex++) {
        getline(cin, command);
        executeCursorAction(command);
    }

    // cursor 왼쪽 출력 (정방향으로 순회)
    vector<char>::iterator cursorIterator;
    for (cursorIterator = cursorLeft.begin(); cursorIterator != cursorLeft.end(); ++cursorIterator) {
        printf("%c", *cursorIterator);
    }
    
    // coursor 오른쪽 출력 (역방향으로 pop 하며 순회)
    while (!cursorRight.empty()) {
        printf("%c", cursorRight.back());
        cursorRight.pop_back();
    }

    
    
}

