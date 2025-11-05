#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <stack>
#include <bitset>
#include <algorithm>


/// <summary>
//결국 4개의 분면으로 나뉘어짐.
// //N = 2
//
//(0, 0)~(1, 1) = > 제 2사분면
//(0, 2)~(1, 3) = > 제 1사분면
//(2, 0)~(3, 1) = > 제 3사분면
//(2, 2)~(3, 3) = > 제 4사분면
//
//N = 3
//
//(0, 0)~(3, 3) = > 제 2사분면
//(0, 4)~(3, 7) = > 제 1사분면
//(4, 0)~(7, 3) = > 제 3사분면
//(4, 4)~(7, 7) = > 제 4사분면
//
//
//기준선은 정중앙에 = > 2 ^ (n - 1)
/// </summary>
using namespace std;


void init();


int solv(int n, int x, int y) {
	
	int half;
	int sum = 0;
	//사분면의 중앙 선을 기준으로 재귀적으로 접근
	
	while (n!=0){

		n--;
		half = 1 << n; //2^(n-1)
		
		if( x < half && y < half) { //2사분면
			sum += 0;
		}
		else if (x < half && y >= half) { //1사분면
			sum += half * half;
			y -= half;
		}
		else if (x >= half && y < half) { //3사분면
			sum += 2 * half * half;
			x -= half;
		}
		else { //4사분면
			sum += 3 * half * half;
			x -= half;
			y -= half;
		}
	}

	return sum;

}





int main()
{
	init();

	int n, r, c;
	cin >> n>>r>>c;
	cout << solv(n, r, c);
}

void init() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
}



	