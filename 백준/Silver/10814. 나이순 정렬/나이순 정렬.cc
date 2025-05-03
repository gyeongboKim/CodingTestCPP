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
 
