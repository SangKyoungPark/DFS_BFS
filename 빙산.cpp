#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>
using namespace std;

struct S_POS {
	int y{};
	int x{};
};

int n{}, m{};
int map[310][310]{};
bool v[310][310]{};
int nRes{};
bool flag{};

int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };

void removeIce() {
	queue <S_POS> Q{};
	int temp[310][310]{};
	
	for (int i = 1; i < n-1; i++) {
		for (int j = 1; j < m-1; j++) {
			temp[i][j] = map[i][j];
			if (temp[i][j] > 0)	Q.push({ i,j });
		}
	}

	while (!Q.empty()) {
		S_POS cur = Q.front();
		Q.pop();

		int cnt = 0;
		for (int k = 0; k < 4; k++) {
			S_POS p = { cur.y + dy[k], cur.x + dx[k] };
			if (p.y < 0 || p.x < 0 || p.y >= n || p.x >= m)	continue;
			if (map[p.y][p.x] == 0)	cnt++;
		}
		temp[cur.y][cur.x] -= cnt;

		if (temp[cur.y][cur.x] < 0) {
			temp[cur.y][cur.x] = 0;
		}
	}
	
	//map update
	for (int i = 1; i < n-1; i++) {
		for (int j = 1; j < m-1; j++) {
			map[i][j] = temp[i][j];
		}
	}
}

void bfs(S_POS s) {
	queue <S_POS> Q{};
	Q.push(s);
	v[s.y][s.x] = true;

	while (!Q.empty()) {
		S_POS cur = Q.front();
		Q.pop();

		int cnt = 0;
		for (int k = 0; k < 4; k++) {
			S_POS p = { cur.y + dy[k], cur.x + dx[k] };
			if (p.y < 0 || p.x < 0 || p.y >= n || p.x >= m)	continue;
			if (map[p.y][p.x] > 0 && !v[p.y][p.x]) {
				Q.push(p);
				v[p.y][p.x] = true;
			}
		}
	}
}

int checkMap() {
	//init
	for (int i = 1; i < n-1; i++) {
		for (int j = 1; j < m-1; j++) {
			v[i][j] = false;
		}
	}

	//logic
	int cnt = 0;
	for (int i = 1; i < n-1; i++) {
		for (int j = 1; j < m-1; j++) {
			if (map[i][j] > 0 && !v[i][j]) {
				bfs({ i,j });
				cnt++;
			}
		}
	}
	if (cnt == 0)	flag = true;
	return cnt;
}

int main() {
	//input data
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	//init
	nRes = 0;

	//logic
	// 다 녹았는지 or 2개 이상으로 나뉘어 있는지 판단
	// 공백 수 만큼 녹임
	
	while (true) {
		int cnt = checkMap();
		if (cnt >= 2)	break;
		if (flag) {
			nRes = 0;
			break;
		}
		removeIce();
		nRes++;
	}

	/*
	printf("\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
	*/

	//result
	printf("%d\n", nRes);
	return 0;
}