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

class Member {
public:
	int age;
	int count;
	string name;
	Member(int age, string name, int count) : age(age), name(name), count(count) { }

	bool operator > (const Member& other) const {
		//만약 나이가 같으면 가입한 순으로 정렬
		if (age == other.age) return count > other.count;
		return age > other.age;
	}

};


int main() 
{
	//오름차순 우선순위 (작은 수 부터 정렬)
	priority_queue<Member, vector<Member>, greater<Member>> pq;

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	int testCount; 
	cin >> testCount;
	
	
	for (int i = 0; i < testCount; i++) 
	{
		int age;
		string name;
		cin >> age >> name;
		
		pq.push(Member(age, name, i));
	}

	
	while (!pq.empty()) 
	{
		cout << pq.top().age <<" "<< pq.top().name << "\n";
		pq.pop();

	}
	return 0;


}
 
