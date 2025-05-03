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

class Position {
public:
	int PosX;
	int PosY;
	
	Position(int PosX, int PosY) : PosX(PosX), PosY(PosY) {}

	bool operator > (const Position& other) const {
		//X좌표를 비교하고 X좌표가 같은경우 Y좌표 비교
		if (PosX == other.PosX) return PosY > other.PosY;
		return PosX > other.PosX;
	}

};


int main()
{
	//오름차순 우선순위 (작은 수 부터 정렬)
	priority_queue<Position, vector<Position>, greater<Position>> pq;

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int testCount;
	cin >> testCount;


	for (int i = 0; i < testCount; i++)
	{
		int PosX;
		int PosY;
		cin >> PosX >> PosY;

		pq.push(Position(PosX, PosY));
	}


	while (!pq.empty())
	{
		cout << pq.top().PosX << " " << pq.top().PosY << "\n";
		pq.pop();

	}
	return 0;


}
