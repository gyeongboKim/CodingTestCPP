#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>

/// <summary>
///  1개의 막대를 기준으로 기준 막대보다 높은 막대의 개수를 
///  기준막대 보다 작은 막대가 나올 때 까지 카운트한뒤 넓이를 계산
/// 
///  이를 N개의 모든 막대를 기준을 해보며 최대 넓이를 산출
/// 
/// ==>  O(n^2)   n번을 n번
/// 1. i 번째 막대가 i-1 막대보다 작은지 확인한다
///		i번째 막대가 i-1 막대 보다 크다면 push.
/// 2. 작다면 스택의 top에 있는 막대를 pop하고, 
///		pop한 막대기의 높이 * pop한 막대기와 넣을 막대기 사이의 거리 
///		를 계산하며 pop한 막대기로 만들 수 있는 최대 직사각형의 넓이를 구한다.
///		2의 과정은 stack이 비어있을 때 까지 반복된다.
///		(pop한 막대기의 높이는 오름차순이기 때문에 같거나 줄어들게 되고,
///		 너비는 pop할 수록 넣을 막대기와 거리가 멀어지므로 늘어나게 된다. 아직 i번째 막대는 push하기 전 상태.)
///		
/// 
/// </summary>

using namespace std;

long long heightArray[100001];

int main() 
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	

	while (true)
	{
		stack<int> indexStack;
		int testCount = 0;
		long long maxArea = 0;
		cin >> testCount;

		if (testCount == 0)
		{
			break;
		}

		for (int i = 0; i < testCount; i++)
		{
			//우선 막대들의 높이 정보를 입력받아 배열에 저장
			cin >> heightArray[i];
		}

		for (int i = 0; i < testCount; i++)
		{
			//	스택이 차있을 때 && 넣을 막대가 이전 막대보다 작은경우
			while (!indexStack.empty() && heightArray[i] < heightArray[indexStack.top()]) {
				long long heightTop = heightArray[indexStack.top()];

				int width = i;

				//스택의 막대기를 pop 하고 (i-1, i-2 ...)
				indexStack.pop();

				// 스택이 차있으면 직사각형 너비 계산
				if (!indexStack.empty()) {
					// pop한 막대기로 부터의 너비 
					width = i - 1 - indexStack.top();
				}
				//직사각형 최대값 갱신
				if (maxArea < width * heightTop) {
					maxArea = width * heightTop;
				}
			}

			indexStack.push(i);
		}

		//모든 막대들의 순회를 마쳐도 스택에 처리되지 않은 막대들의 인덱스들이 남아있다면,
		
		while (!indexStack.empty())
		{
			long long heightTop = heightArray[indexStack.top()];
			//(위의 width = i 에서 i 가 최대 일 때 이므로 width는 
			int width = testCount;
			indexStack.pop();

			if(!indexStack.empty())
			{
				width = testCount - 1 - indexStack.top();
			}
			if (maxArea < width * heightTop)
			{
				maxArea = width * heightTop;
			}
		}

		cout << maxArea <<'\n';
	}
}
 
