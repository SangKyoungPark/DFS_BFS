#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>
using namespace std;

int n{}, k{};
int v[100010]{};
int nRes{};

void bfs() {
	queue <int> Q{};
	Q.push(n);
	v[n] = 1;

	while (true) {
		int cur = Q.front();
		Q.pop();

		if (cur == k) {
			nRes = v[cur]-1;
			break;
		}
		if (cur - 1 >= 0 && v[cur - 1] == 0) {
			v[cur - 1] = v[cur] + 1;
			Q.push(cur - 1);
		}
		if (cur + 1 <= 100000 && v[cur + 1] == 0) {
			v[cur + 1] = v[cur] + 1;
			Q.push(cur + 1);
		}
		if (cur * 2 <= 100000 && v[cur * 2] == 0) {
			v[cur * 2] = v[cur] + 1;
			Q.push(cur * 2);
		}
	}
}

int main() {
	//input data
	scanf("%d %d", &n, &k);

	//logic
	bfs();

	//result
	printf("%d\n", nRes);
	return 0;
}