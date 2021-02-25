#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define SIZE 30

struct S_POS {
	int y{};
	int x{};
};

int n{};
int map[SIZE][SIZE]{};
int nArr[SIZE * SIZE]{};

int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };

int bfs(S_POS s) {
	queue <S_POS> Q;
	int cnt = 1;

	Q.push(s);
	map[s.y][s.x] = 0;

	while (!Q.empty()) {
		S_POS cur = Q.front();
		Q.pop();

		for (int i = 0; i < 4; i++) {
			S_POS p = { cur.y + dy[i], cur.x + dx[i] };
			if (p.y < 0 || p.x < 0 || p.y >= n || p.x >= n)	continue;
			if (map[p.y][p.x]) {
				map[p.y][p.x] = 0;
				cnt++;
				Q.push(p);
			}
		}
	}
	return cnt;
}

int main() {
	//input
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	//init
	int idx = 0;

	//logic
	while (1) {
		bool flag = true;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] == 1) {
					nArr[idx] = bfs({ i,j });
					idx++;
					flag = false;
					break;
				}
			}
		}
		if (flag)	break;
	}
	sort(nArr, nArr + idx);


	//result
	printf("%d\n", idx);
	for (int i = 0; i < idx; i++) {
		printf("%d\n", nArr[i]);
	}
	return 0;
}