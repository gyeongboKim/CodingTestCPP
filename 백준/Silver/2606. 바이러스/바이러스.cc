#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <stack>
#include <bitset>
#include <algorithm>


/// <summary>
///
/// </summary>
using namespace std;


void init();
using Graph = vector<vector<int>>;
vector<bool> visited;
int visitedCount = 0;


void repeatInput(int n, Graph& G) {
	for (int i = 0; i < n; i++) {
		int startIndex, endIndex;
		cin >> startIndex >> endIndex;
		G[startIndex].push_back(endIndex);
		G[endIndex].push_back(startIndex);
	}
}

void DFS(int startIndex, Graph& G) {
	visited[startIndex] = true;
	for (int nextIndex : G[startIndex]) {
		if (!visited[nextIndex]) {
			visitedCount++;
			DFS(nextIndex, G);
		}
	}
}


int main()
{
	init();
	int countOfIndex;
	cin >> countOfIndex;
	Graph G(countOfIndex + 1);
	visited.assign(countOfIndex + 1, false);
	int countOfNetwork;
	cin >> countOfNetwork;
	repeatInput(countOfNetwork, G);
	DFS(1, G);
	cout << visitedCount;
}

void init() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
}



