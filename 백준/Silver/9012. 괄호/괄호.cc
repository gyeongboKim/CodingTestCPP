#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stack>
#include <string>
#include <sstream>

/// <summary>
/// 9012 괄호
/// 1. 첫 번째 줄 입력 데이터의 수를 나타내는 T 입력
/// 2. 괄호들을 T줄 입력 (2 이상 50 이하)
/// 2-1. () 나 (())() 와 같이 괄호 체계가 정확히 되어 있는 것은 VPS => YES 출력
/// 2-2 (()나 (()( 같이 괄호 체계가 망가진 경우 문자열 => NO 출력 
/// 
/// 방법 
/// ( -> 저장
/// ) -> pop
/// testcase
///     1. () 같은경우
///         empty() true
///     2. )( 같지만 망가진 경우
///         empty() false
///     3. (()  '(' 가 많은 경우
///         empty() true
///     4. ())  ')' 가 많은 경우
///         pop 해야 하지만 empty이기 때문에 false
/// 
/// stack 을 어떻게 활용할 것인가 신경쓸 것. 
/// </summary>

bool isVPS(std::stack<char> &stackVPS, std::string Sentence) {
    
    
    //스택 초기화
    while (!stackVPS.empty()) {
        stackVPS.pop();
    }

    //1.문자열을 스택에 저장
    for (char parenthesis : Sentence) {
        if (parenthesis == '(')
        {
            stackVPS.push(parenthesis);
        }
        else if (parenthesis == ')') {
            if (stackVPS.empty()) {
                return false;
            }
            stackVPS.pop();
        }
    }

    // 스택이 비어있고 count도 0일 때
    return stackVPS.empty();

}

int main() {
    std::stack<char> stackVPS;
    int testCount = 0;
    std::string parenthesisSentence;
    scanf("%d" , &testCount);
    std::cin.ignore();
    //T번 만큼 입력
    for (int t = 0; t < testCount; t++) {
        //PS(괄호 문자열) 입력
        getline(std::cin, parenthesisSentence);

        if (isVPS(stackVPS, parenthesisSentence)) {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
    }
    return 0;
}
