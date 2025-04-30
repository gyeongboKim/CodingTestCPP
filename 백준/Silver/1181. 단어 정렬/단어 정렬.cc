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
/// 길이가 짧은 것 부터 정렬
/// 길이가 같으면 첫 문자 비교
///		사전순 정렬
/// </summary>

using namespace std;

struct Word
 {
 public:
	string word;
	size_t length;

	Word(string word) : word(word), length(word.length()) { }

	bool operator > (const Word& other) const
	{
		if (length == other.length) return word > other.word;	//길이가 같다면 문자열 비교
		return length > other.length;
	}
	
};



int main() 
{
	//오름차순 우선순위 큐 (길이가 짧은 단어부터 정렬)
	priority_queue<Word, vector<Word>, greater<Word>> pq;
	//중복 방지를 위한 unordered_set
	unordered_set<string> uniqueWords;

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	int testCount; 
	cin >> testCount;
	
	for (int i = 0; i < testCount; i++) 
	{
		string line;
		cin >> line;
		
		//중복된 단어가 아니라면 우선순위 큐에 추가
		if (uniqueWords.find(line) == uniqueWords.end())
		{
			uniqueWords.insert(line);
			pq.push(Word(line));
		}
	
	}

	//우선순위 큐에서 정렬된 단어 출력
	while (!pq.empty()) 
	{
		cout << pq.top().word << "\n";
		pq.pop();

	}
	return 0;


}
 
