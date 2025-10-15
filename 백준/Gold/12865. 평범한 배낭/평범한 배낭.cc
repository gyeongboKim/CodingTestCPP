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
/// 
/// </summary>
using namespace std;

void init();
int dp[101][100001];							//최대 이익

struct Thing {
	int weight;
	int value;
};
class Knapsack {
private:
	int numOfThings;
	int weightLimit;
	
public:
	
	vector<Thing> things;
	Knapsack(int numOfThings, int weightLimit) : numOfThings(numOfThings), weightLimit(weightLimit) {}
	
	void printLimit() {
		cout << numOfThings <<' ' << weightLimit;
	}
	
	void insert() {
		for (int i = 0; i < numOfThings; i++) {
			int weight;
			int value;
			cin >> weight >> value;

			Thing thing;
			thing.weight = weight;
			thing.value = value;
			things.push_back(thing);
			
			
		}
	}
	
	void solv() {
		//dp 배열 초기화
		for (int i = 0; i <= numOfThings; i++) {
			for (int w = 0; w <= weightLimit; w++) {
				dp[i][w] = 0;
			}
		}
		for (int i = 1; i <= numOfThings; i++) {
			for (int knapsackLimit = 0; knapsackLimit <= weightLimit; knapsackLimit++) {		//무게 제한을 1부터 weightLimit까지 늘려가면서 i번째 물건을 넣을 수 있는지 확인
				// i번째 물건을 넣을 수 있는 경우
				if (knapsackLimit - things[i-1].weight >= 0) {
					// i번째 물건을 넣지 않는 경우와 넣는 경우 중 최대 값
					dp[i][knapsackLimit] = max(
						dp[i - 1][knapsackLimit],
						dp[i - 1][knapsackLimit - things[i - 1].weight] + things[i-1].value);
				}else{
					// i번째 물건을 넣을 수 없는 경우
					// 이전으로 최대 값 유지
					dp[i][knapsackLimit] = dp[i - 1][knapsackLimit];
				}
			}
		}
		cout << dp[numOfThings][weightLimit];
	}
	void printThings() {
		cout << "things 내용:" << endl;
		for (const auto& thing : things) {
			cout << "weight: " << thing.weight << ", value: " << thing.value << endl;
		}
	}
	
};


int main()
{
	init();
	int numOfThings;
	int weightLimit;

	cin >> numOfThings >> weightLimit;
	Knapsack knapsack(numOfThings, weightLimit);
	knapsack.insert();
	knapsack.solv();
	

}

void init() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
}



