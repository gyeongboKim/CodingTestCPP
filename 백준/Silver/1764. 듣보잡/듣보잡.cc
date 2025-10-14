#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <list>
#include <sstream>
#include <stack>
#include <bitset>
#include <unordered_map>
/// <summary>
///
/// 
/// </summary>
using namespace std;

void init();
void repeatInput(int a, int b, list<string> list);

const int NUMBER_OF_ALPHABET = 26;
int toIndex(char ch) { return ch - 'a';}
class Trie {
public:
	Trie* childeren[NUMBER_OF_ALPHABET];	// 길이별로 트라이를 저장할 배열
	unordered_map<string, Trie*> map;
	bool isEnd;	// 단어의 끝인지 여부
	Trie() : childeren(), isEnd(false) {}

	void Insert(string& word, int index) {
		if (index == word.length()) {
			this->isEnd = true;
			return;
		}
		else {
			int next = toIndex(word[index]);
			if (childeren[next] == nullptr)
				childeren[next] = new Trie();
			childeren[next]->Insert(word, index + 1);
		}
	}
	
	// 단어가 존재하는지 확인
	bool Search(string& word, int depth) {
		if (depth == word.length() && isEnd)
			return true;
		if(depth == word.length() && isEnd)
			return false;
		int next = toIndex(word[depth]);
		if (childeren[next] == nullptr)
			return false;
		return childeren[next]->Search(word, depth + 1);
	}
	
};



int main()
{
	init();
	list<string> neverHeardAndSeen;
	int numberOfFirstInput;
	int numberOfSecondInput;
	cin >> numberOfFirstInput >> numberOfSecondInput;
	
	
	repeatInput(numberOfFirstInput, numberOfSecondInput, neverHeardAndSeen);
}

void init() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
}


void repeatInput(int a, int b, list<string> neverHeardAndSeen) {
	Trie* root = new Trie();
	int count = 0;
	for (int i = 0; i < a; ++i) {
		string neverHeardName;
		cin >> neverHeardName;
		root->Insert(neverHeardName, 0);
	}
	for (int j = 0; j < b; ++j) {
		string neverBeforeSeenName;
		cin >> neverBeforeSeenName;
		if (root->Search(neverBeforeSeenName, 0)) {
			count++;
			neverHeardAndSeen.push_back(neverBeforeSeenName);
		}
	}
	neverHeardAndSeen.sort();
	cout << count << '\n';
	for(string &name : neverHeardAndSeen) {
		cout << name << '\n';
	}
}