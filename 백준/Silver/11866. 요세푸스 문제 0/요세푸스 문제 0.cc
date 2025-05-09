#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>


/// <summary>
///
/// 요세푸스 수
/// 1. 큐에 모든 수를 넣는다
/// 2. i가 0부터 K 까지
///		2-1 i가 m-1이 아닌경우 - queue를 한칸 돌린다.
///		2-2 i가 m-1 이고, queue의 사이즈가 1보다 높은경우
///			(front에 있는 숫자가 K번째 수 이므로)
///			수와 ',' 출력 후 pop 한다.
///		2-3 i가 m-1이고, queue의 사이즈가 1인 경우
///			마지막 수를 출력 후 pop 한다. 이후 큐가 비게되므로 while을 빠져나온다.
///	3. 큐가 비어있을 때 까지 반복한다.
/// 
/// </summary>

using namespace std;



int main()
{
	queue<int> q;
	int N, K;
	cin >> N >> K;
	for (int i = 1; i <= N; i++)
		q.push(i);
	cout << "<";
	while (!q.empty()) {
		for (int i = 0; i < K; i++) {
			if (i != K - 1)
				q.push(q.front());
			else if (q.size() > 1)
				cout << q.front() << ", ";
			else
				cout << q.front();
			q.pop();
		}
	}
	cout << ">";
}
