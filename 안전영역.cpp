#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct S_POS {
	int y{};
	int x{};
};

int n{};
int map[110][110]{};
bool check[110][110]{};
int nRes{};
int top{}, btm{};

void init() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			check[i][j] = false;
		}
	}
}

void setMap(int h) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] <= h) {
				check[i][j] = true;
			}
		}
	}
}

void bfs(S_POS pp) {
	queue <S_POS> Q{};
	int dy[] = { 0,0,1,-1 };
	int dx[] = { 1,-1,0,0 };

	Q.push(pp);

	while (!Q.empty()) {
		S_POS cur = Q.front();
		Q.pop();

		for (int k = 0; k < 4; k++) {
			S_POS nPos = { cur.y + dy[k], cur.x + dx[k] };
			if (nPos.y < 0 || nPos.x < 0 || nPos.y >= n || nPos.x >= n)	continue;
			if (!check[nPos.y][nPos.x]) {
				Q.push(nPos);
				check[nPos.y][nPos.x] = true;
			}
		}
	}
}

int checkMap() {
	// 물을 제외한 안전영역이 몇개인지 판단해서 돌려줌
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!check[i][j]) {
				bfs({ i,j });
				cnt++;
			}
		}
	}
	return cnt;
}


void solve(int h) {
	//1. 모든 맵 탐색 -> btm ~ top까지
	//2. 물 높이 셋팅 (새로운 맵) -> 해당 맵을 가지고 안전영역 판단
	init();
	setMap(h);
	nRes = max(nRes, checkMap());
}

int main() {
	//input data
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
			top = max(top, map[i][j]);
			btm = min(btm, map[i][j]);
		}
	}
	
	//init
	nRes = 1;

	//logic
	for (int i = btm; i <= top; i++) {
		solve(i);
	}

	//result
	printf("%d\n", nRes);
	return 0;
}