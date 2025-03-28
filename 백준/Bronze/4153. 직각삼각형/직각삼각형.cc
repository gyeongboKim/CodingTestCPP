#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>

/// <summary>
///  
/// </summary>

using namespace std;



int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);


	while (true) {
		int heru, ausar, auset;
		cin >> ausar >> auset >> heru;
		if (ausar + auset + heru == 0) {
			break;
		}
		if (pow(ausar, 2) + pow(auset, 2) == pow(heru, 2)) {
			cout << "right"<<"\n";
		}
		else if (pow(ausar, 2) + pow(heru, 2) == pow(auset, 2)) {
			cout << "right" << "\n";
		}
		else if (pow(heru, 2) + pow(auset, 2) == pow(ausar, 2)) {
			cout << "right" << "\n";
		}
		else {
			cout << "wrong" << "\n";
		}
	}
}