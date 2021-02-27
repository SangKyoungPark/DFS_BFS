#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

int n{}, m{};
int nRes{};
int pivot{}, dest{};
int map[110][110]{};
bool check[110]{};
bool flag{};

void dfs(int cur, int len) {
	if (cur == dest) {
		nRes = len;
		flag = true;
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!check[i] && map[cur][i]) {
			check[i] = true;
			dfs(i, len + 1);
			check[i] = true;
		}
	}
}

int main() {
	//input data
	scanf("%d", &n);
	scanf("%d %d", &pivot, &dest);
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int y{}, x{};
		scanf("%d %d", &y, &x);
		map[y][x] = 1;
		map[x][y] = 1;
	}

	//init
	flag = false;

	//logic
	dfs(pivot,0);
	if (!flag)	nRes = -1;

	//result
	printf("%d\n", nRes);
	return 0;
}