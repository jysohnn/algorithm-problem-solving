#include <iostream>						// 입출력함수들을 쓰기 위함
#include <vector>						// vector 자료구조를 쓰기 위함

using namespace std;					// namespace std::를 생략하기 위함

typedef pair<int, int> pii;				// pair<int, int>를 pii로 재정의

int map[9][9];							// 스도쿠 게임판 상태배열
vector<pii> blank;						// 빈칸의 좌표를 저장하는 vector

vector<int> promising(int x, int y)		// promising한 숫자들을 vector로 반환하는 함수
{
	vector<int> ret;					// 반환 vector
	int bx = x / 3, by = y / 3;			// 3x3의 블록의 좌표
	bool check[10] = { 0 };				// 1~9 중 promising한 숫자를 체크하기 위함
	for (int i = 0; i < 9; i++) check[map[x][i]] = 1, check[map[i][y]] = 1;
	for (int i = 0; i < 3; i++)			// 이미 게임판에 있는 숫자들 check (가로, 세로, 같은블록)
		for (int j = 0; j < 3; j++) check[map[bx*3 + i][by*3 + j]] = 1;
	for (int i = 1; i < 10; i++) if (!check[i]) ret.push_back(i);
	return ret;							// check되지 않은 숫자들이 promising하므로, ret에 push하고 반환
}

bool solve(int k)						// backtracking으로 solution을 찾는 함수
{										// k번째 blank의 좌표를 x, y에 저장
	int x = blank[k].first, y = blank[k].second;
	vector<int> p = promising(x, y);	// p에 x, y좌표에 올 수 있는 promising한 숫자들 저장
	for (int i = 0; i < p.size(); i++)	// promising한 숫자들에 대하여
	{
		map[x][y] = p[i];				// 해당 좌표를 p[i]로 갱신하고
		if (k == blank.size() - 1) return 1;
										// k가 마지막 blank인데, promising한 숫자가 있다는 것은
										// 스도쿠가 완성되었다는 말이므로, true를 반환하며 함수종료
		if (solve(k + 1)) return 1;		// 상태를 유지하고 k+1번째 blank에 대해서 재귀호출하고
										// true를 반환한다면 더 이상 탐색하지 않고 이어서 true를 반환하고 함수종료
	}
	map[x][y] = 0;						// backtracking을 하기 위해, 해당 조합에서 solution을 찾지 못하였다면
	return 0;							// 1~9사이의 숫자가 아닌 0으로 다시 갱신해주고 false를 반환
}

int main()
{
	for (int i = 0; i < 9; i++)			// 스도쿠 게임판의 상태를 입력받는다.
		for (int j = 0; j < 9; j++)
		{
			scanf("%d", &map[i][j]);	// blank라면 blank vector에 해당좌표를 push한다.
			if (!map[i][j]) blank.push_back(pii(i, j));
		}
	solve(0);							// backtracking으로 solution 탐색
	for (int i = 0; i < 9; i++)			// 완성 된 스도쿠판 출력
	{
		for (int j = 0; j < 9; j++) printf("%d ", map[i][j]);
		putchar('\n');
	}
	return 0;
}