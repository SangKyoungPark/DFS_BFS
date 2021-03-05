#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
using namespace std;

int map[105][105]{};

void init() {
    for (int i = 0; i < 102; i++) {
        for (int j = 0; j < 102; j++) {
            map[i][j] = 0;
        }
    }
}


int main() {
    int tc{}, n{};
    scanf("%d", &tc);
    for (int t = 0; t < tc; t++) {
        //배열 초기화
        init();

        //편의점 갯수
        scanf("%d", &n);
        int y{}, x{};

        pair<int, int> start{}, end{};

        scanf("%d %d", &y, &x);

        //시작 지점
        start = make_pair(y, x);
        vector<pair<int, int>> v;

        //편의점 좌표
        for (int j = 0; j < n; j++) {
            scanf("%d %d", &y, &x);
            v.push_back(make_pair(y, x));
        }

        //도착 지점
        scanf("%d %d", &y, &x);
        end = make_pair(y, x);


        //각 지점에서 다른지점으로 갈수있는 지 확인.
        for (int i = 0; i < n + 2; i++) {
            for (int j = 0; j < n + 2; j++) {
                if (i == j)continue;
                if (map[i][j])continue;

                //start
                if (i == 0) {
                    //도착지점
                    if (j == n + 1) {
                        if (abs(start.first - end.first) + abs(start.second - end.second) <= 1000) {
                            map[i][j] = 1;
                            map[j][i] = 1;
                        }
                    }
                    //편의점
                    else {
                        if (abs(start.first - v[j - 1].first) + abs(start.second - v[j - 1].second) <= 1000) {
                            map[i][j] = 1;
                            map[j][i] = 1;
                        }

                    }
                }

                //end
                else if (i == n + 1) {
                    //출발지점
                    if (j == 0) {
                        if (abs(start.first - end.first) + abs(start.second - end.second) <= 1000) {
                            map[i][j] = 1;
                            map[j][i] = 1;
                        }
                    }
                    //편의점
                    else {
                        if (abs(end.first - v[j - 1].first) + abs(end.second - v[j - 1].second) <= 1000) {
                            map[i][j] = 1;
                            map[j][i] = 1;
                        }
                    }
                }
                //편의점
                else {
                    //출발지점이거나 도착지점이면 
                    if (j == 0 || j == n + 1)continue;
                    else {
                        //다른 편의점
                        if (abs(v[i - 1].first - v[j - 1].first) + abs(v[i - 1].second - v[j - 1].second) <= 1000) {
                            map[i][j] = 1;
                            map[j][i] = 1;
                        }
                    }

                }


            }
        }

        //플루이드 와샬 알고리즘 -> 가중치로 최단거리 탐색
        for (int k = 0; k < n + 2; k++) {
            for (int i = 0; i < n + 2; i++) {
                for (int j = 0; j < n + 2; j++) {
                    if (map[i][j])continue;

                    map[i][j] = max(map[i][j], map[i][k] + map[k][j]);
                    if (map[i][j] == 2) {
                        map[i][j] = 1;
                        map[j][i] = 1;
                    }
                    else map[i][j] = 0;
                }
            }
        }

        //map[시작지점][도착지점 ==1 이면 happy 아니면 sad
        if (map[0][n + 1])cout << "happy" << "\n";
        else cout << "sad" << "\n";
    }
}
