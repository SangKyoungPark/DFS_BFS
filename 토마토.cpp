#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define SIZE 110

struct INFO {
	int f{}, y{}, x{};
};

int n{}, m{}, h{};
int nRes{};
int map[SIZE][SIZE][SIZE]{};
bool check[SIZE][SIZE][SIZE]{};
queue <INFO> Q{};

int df[] = { 0,0,0,0,1,-1 };
int dy[] = { 1,-1,0,0,0,0 };
int dx[] = { 0,0,1,-1,0,0 };

void bfs() {
	while (!Q.empty()) {
		INFO cur = Q.front();
		Q.pop();

		for (int k = 0; k < 6; k++) {
			INFO p = { cur.f + df[k], cur.y + dy[k], cur.x + dx[k] };
			if (p.f < 0 ||p.y < 0 || p.x < 0 || p.f >= h || p.y >= n || p.x >= m)	continue;
			if (!check[p.f][p.y][p.x] && map[p.f][p.y][p.x] == 0) {
				check[p.f][p.y][p.x] = true;
				Q.push(p);
				map[p.f][p.y][p.x] = map[cur.f][cur.y][cur.x] + 1;
			}
		}
	}

	for (int f = 0; f < h; f++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[f][i][j] == 0) {
					nRes = -1;
					return;
				}
				nRes = max(nRes, map[f][i][j]);
			}
		}
	}
	nRes -= 1;
}

int main() {
	//input data
	scanf("%d %d %d", &m, &n, &h);
	for (int f = 0; f < h; f++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				scanf("%d", &map[f][i][j]);
				
				//init
				if (map[f][i][j] == 1) {
					Q.push({ f, i, j });
					check[f][i][j] = true;
				}
			}
		}
	}

	//logic
	bfs();
	//result
	printf("%d", nRes);

	return 0;
}