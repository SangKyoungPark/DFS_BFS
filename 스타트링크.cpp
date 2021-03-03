#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>
using namespace std;

#define MAX 1000010

int F, S, G, U, D;
int v[MAX]{};

int bfs() {
    queue <int> Q{};
    Q.push(S);
    v[S] = 1;

    while (!Q.empty()) {
        int cur = Q.front();
        Q.pop();

        if (cur == G)
            return v[cur] - 1;

        int nextFloor[2] = { cur + U, cur - D };

        for (int i = 0; i < 2; i++)
            if (1 <= nextFloor[i] && nextFloor[i] <= F && v[nextFloor[i]] == 0) {
                v[nextFloor[i]] = v[cur] + 1;
                Q.push(nextFloor[i]);
            }
    }
    return -1;
}



int main() {
    //input data
    scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);
    
    //logic
    int result = bfs();
    
    //result
    if (result == -1)
        printf("use the stairs\n");
    else
        printf("%d\n", result);
    
    return 0;
}