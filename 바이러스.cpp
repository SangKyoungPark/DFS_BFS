#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int n, m, v;
int map[1010][1010]{};
int check[1010]{};

void bfs(int s) {
	queue <int> Q;
	Q.push(s);
	check[s] = 1;

	while (!Q.empty()) {
		int idx = Q.front();
		Q.pop();
		//printf("%d ", idx);
		for (int i = 1; i <= n; i++) {
			if (!check[i] && map[idx][i]) {
				check[i] = 1;
				Q.push(i);
			}
		}
	}
}

int main() {
	//input
	scanf("%d", &n);
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int s, e;
		scanf("%d %d", &s, &e);
		map[s][e] = 1;
		map[e][s] = 1;
	}

	bfs(1);

	int cnt = 0;
	for (int i = 2; i <= n; i++) {
		if (check[i]) cnt++;
	}

	printf("%d", cnt);
	return 0;
}