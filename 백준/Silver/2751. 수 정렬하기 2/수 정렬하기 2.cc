#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <queue>
#include <unordered_set>
#include <iostream>
/// <summary>
///
/// N개의 수가 주어졌을 때, 이를 오름차순으로 정렬하는 프로그램을 작성하시오.
/// 
/// </summary>

using namespace std;




int main() 
{
	//오름차순 우선순위 (작은 수 부터 정렬)
	priority_queue<int, vector<int>, greater<int>> pq;
	//중복 방지를 위한 unordered_set
	unordered_set<int> uniqueWords;

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	int testCount; 
	cin >> testCount;
	
	for (int i = 0; i < testCount; i++) 
	{
		int line;
		cin >> line;
		
		//중복된 숫자가 아니라면 우선순위 큐에 추가
		if (uniqueWords.find(line) == uniqueWords.end())
		{
			uniqueWords.insert(line);
			pq.push(line);
		}
	
	}

	//우선순위 큐에서 정렬된 숫자 출력
	while (!pq.empty()) 
	{
		cout << pq.top() << "\n";
		pq.pop();

	}
	return 0;


}
 
