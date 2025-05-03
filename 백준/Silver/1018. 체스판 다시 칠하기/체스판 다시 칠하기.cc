#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cmath>
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
	int x = 0, y = 0;

	cin >> x >> y;
	
	vector <vector<char>> board(x, vector<char>(y, 0));
	string color;
	
	for (int i = 0; i < x; i++)
	{
		cin >> color;
		for (int j = 0; j < color.size(); j++)
		{	
			board[i][j] = (char)color[j];
		}
	}

	
	/*for (int i = 0; i < board.size(); i++) 
	{
		for (int j = 0; j < board[i].size(); j++)
		{
			cout << board[i][j];
		}
		cout << "\n";
	}*/
		
	//8X8 크기 씩 이동하면서 검사
	int minMatch = 64;

	for (int i = 0; i <= x - 8; i++)
	{
		for (int j = 0; j <= y - 8; j++)
		{
			int whiteStartMatch = 0;
			int blackStartMatch = 0;
			for (int slideX = 0; slideX < 8; slideX++) 
			{
				for (int slideY = 0; slideY < 8; slideY++)
				{
					if ((slideX + slideY) % 2 == 0)
					{
						//white 시작일 때
						if (board[i + slideX][j + slideY] == 'W') 
						{
							whiteStartMatch++;
						}
						else
						{
							blackStartMatch++;
						}
							

					}
					else
					{
						if (board[i + slideX][j + slideY] == 'B')
						{
							whiteStartMatch++;
						}
						else
						{
							blackStartMatch++;
						}
					}
				}
			}
			
			minMatch = min(minMatch, whiteStartMatch);
			minMatch = min(minMatch, blackStartMatch);
			
		}
	}

	cout << minMatch;
}
