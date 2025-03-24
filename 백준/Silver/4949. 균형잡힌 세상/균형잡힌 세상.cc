#include <iostream>
#include <cstdio>
#include <stack>
#include <string>
#include <sstream>
/// <summary>
///  '(' 혹은 '['이 들어오면 push
///  ')' 혹은 ']'이 들어오면 top이 짝이 맞는지 확인 후 pop
///     만약 empty일 경우 
/// 
/// </summary>

using namespace std;

stack<char> parenthesis;

bool isEnd(char frontCharacter ) {
    if (frontCharacter == '.') {
        return true;
    }
    else {
        return false;
    }

}


void stackOperation(char parenthesisCharacter) {
    if (parenthesisCharacter == '(' || parenthesisCharacter == '[') {
        parenthesis.push(parenthesisCharacter);
    }
    else if (parenthesisCharacter == ')') {
        //비어있지 않은지를 먼저 확인 (비어있는 상태에서 ) 가 들어오면 top()에서 읽기 오류 발생)
        if (!parenthesis.empty() && parenthesis.top() == '(') {
            parenthesis.pop();
        }
        //비어있으며 짝이 안맞는 상태에서 )가 들어온 경우 stack을 오염시켜 empty가 나올 수 없게 함.
        else {
            parenthesis.push(parenthesisCharacter);
        }
    }
    else if (parenthesisCharacter == ']') {
        if (!parenthesis.empty() && parenthesis.top() == '[' ) {
            parenthesis.pop();
        }
        else {
            parenthesis.push(parenthesisCharacter);
        }
    }

}

int main()
{
    
    

    while (true) {
        while (!parenthesis.empty()) parenthesis.pop();
        string sentence = "";

        getline(cin, sentence);

        //.온점만 들어올 경우 종료
        if (isEnd(sentence.front())) {
            
            break;
        }
        for (char iteratorCharacter : sentence) {
            stackOperation(iteratorCharacter);
        }

        if (parenthesis.empty()) {
            printf("yes\n");
        }
        else if(!parenthesis.empty()) {
            printf("no\n");
        }
            

    }

    
}

