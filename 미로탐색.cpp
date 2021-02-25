#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>
using namespace std;

struct S_POS {
	int y{};
	int x{};
};

int n{};
int m{};
int map[110][110]{};

int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };

void bfs(S_POS s) {
	queue <S_POS> Q;
	bool check[110][110]{};

	Q.push(s);
	check[s.y][s.x] = true;

	while (!Q.empty()) {
		S_POS cur = Q.front();
		Q.pop();

		for (int i = 0; i < 4; i++) {
			S_POS p = { cur.y + dy[i], cur.x + dx[i] };
			if (p.y < 0 || p.x < 0 || p.y >= n || p.x >= m)	continue;
			if (map[p.y][p.x] && !check[p.y][p.x]) {
				map[p.y][p.x] = map[cur.y][cur.x] + 1;
				Q.push(p);
				check[p.y][p.x] = true;
			}
		}
	}
}

int main() {
	//input
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	//logic
	bfs({ 0, 0 });

	//result
	printf("%d", map[n - 1][m - 1]);
	return 0;
}