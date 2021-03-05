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
        //�迭 �ʱ�ȭ
        init();

        //������ ����
        scanf("%d", &n);
        int y{}, x{};

        pair<int, int> start{}, end{};

        scanf("%d %d", &y, &x);

        //���� ����
        start = make_pair(y, x);
        vector<pair<int, int>> v;

        //������ ��ǥ
        for (int j = 0; j < n; j++) {
            scanf("%d %d", &y, &x);
            v.push_back(make_pair(y, x));
        }

        //���� ����
        scanf("%d %d", &y, &x);
        end = make_pair(y, x);


        //�� �������� �ٸ��������� �����ִ� �� Ȯ��.
        for (int i = 0; i < n + 2; i++) {
            for (int j = 0; j < n + 2; j++) {
                if (i == j)continue;
                if (map[i][j])continue;

                //start
                if (i == 0) {
                    //��������
                    if (j == n + 1) {
                        if (abs(start.first - end.first) + abs(start.second - end.second) <= 1000) {
                            map[i][j] = 1;
                            map[j][i] = 1;
                        }
                    }
                    //������
                    else {
                        if (abs(start.first - v[j - 1].first) + abs(start.second - v[j - 1].second) <= 1000) {
                            map[i][j] = 1;
                            map[j][i] = 1;
                        }

                    }
                }

                //end
                else if (i == n + 1) {
                    //�������
                    if (j == 0) {
                        if (abs(start.first - end.first) + abs(start.second - end.second) <= 1000) {
                            map[i][j] = 1;
                            map[j][i] = 1;
                        }
                    }
                    //������
                    else {
                        if (abs(end.first - v[j - 1].first) + abs(end.second - v[j - 1].second) <= 1000) {
                            map[i][j] = 1;
                            map[j][i] = 1;
                        }
                    }
                }
                //������
                else {
                    //��������̰ų� ���������̸� 
                    if (j == 0 || j == n + 1)continue;
                    else {
                        //�ٸ� ������
                        if (abs(v[i - 1].first - v[j - 1].first) + abs(v[i - 1].second - v[j - 1].second) <= 1000) {
                            map[i][j] = 1;
                            map[j][i] = 1;
                        }
                    }

                }


            }
        }

        //�÷��̵� �ͼ� �˰��� -> ����ġ�� �ִܰŸ� Ž��
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

        //map[��������][�������� ==1 �̸� happy �ƴϸ� sad
        if (map[0][n + 1])cout << "happy" << "\n";
        else cout << "sad" << "\n";
    }
}
