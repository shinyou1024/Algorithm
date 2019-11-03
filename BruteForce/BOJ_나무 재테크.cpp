#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <queue>
#include<deque>
#include<math.h>
using namespace std;

// 각 칸의 상태를 나타내는 구조체
struct Block {
    int yb=5; // 양분의 양
    int add; //겨울마다 보충될 양분의 양
    deque<int> ages; // 심어진 나무들의 나이
    queue<int> dead; // 봄에 죽은 나무들
};

int n, m, k;
Block map[12][12]; // 각 칸마다 나무 구조체 저장

int plant[8][2]{
    // 번식할 때 쓰는 좌표
    {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}
};

void spring() {
    // 각 칸에 심어진 모든 나무에 대해
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            sort(map[i][j].ages.begin(), map[i][j].ages.end()); // 나무 정렬
            for (int k = 0; k < map[i][j].ages.size(); k++) {
                int age = map[i][j].ages[k];

                // 양분을 먹고 나이 + 1
                if (map[i][j].yb >= age) {
                    map[i][j].yb -= age;
                    map[i][j].ages[k]++;
                }

                // 양분을 못 먹는 애가 생기면 그 후로 다 없애주기
                else {
                    int end = map[i][j].ages.size();
                    for (int idx = k; idx < end; idx++) {
                        age = map[i][j].ages.back(); // 이부분 추가하니까 맞음 => age가 맨 처음 죽는 애껄로 들어있어서 그 다음 죽는 애들의 나이가 반영이 안 됨
                        map[i][j].dead.push(age / 2);
                        map[i][j].ages.pop_back();
                        m--; // 나무개수-1

                    }
                    /* 문제점 : pop_back하면서 size가 줄기 때문에 제대로 작동 x
                    for (int idx = k; idx < map[i][j].ages.size(); idx++) {
                        map[i][j].ages.pop_back();
                        m--; // 나무개수-1
                        map[i][j].dead.push(age / 2);
                    }
                    */
                    break;
                }
            }


        }
    }
}

void summer() {
    // 각 칸에 심어진 모든 나무에 대해 죽은 나무가 있으면 양분으로
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            while (!map[i][j].dead.empty()) {
                int e = map[i][j].dead.front();
                map[i][j].dead.pop();
                map[i][j].yb += e;
            }

        }
    }
}

// 가을 겨울
void fw() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            // 가을
            for (int k = 0; k < map[i][j].ages.size(); k++) {
                int age = map[i][j].ages[k];
                // 번식
                if (age % 5 == 0) {
                    for (int p = 0; p < 8; p++) {
                        int ny = i + plant[p][0];
                        int nx = j + plant[p][1]; // 여길 i+palnt[p][1]로 하다니..^^
                        // 범위 체크를 안해서 틀렸었음
                        if (1 <= ny && ny <= n && 1 <= nx && nx <= n) {
                            map[ny][nx].ages.push_front(1); // 한 살짜리 나무 넣어주기
                            m++;
                        }
                    }
                }
            }

            // 겨울
            map[i][j].yb += map[i][j].add;


        }
    }
}


int main() {
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> map[i][j].add; // 추가될 양분
        }
    }
    for (int i = 1; i <= m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        map[x][y].ages.push_back(z);
    }

    for (int year = 0; year < k; year++) {
        spring();
        summer();
        fw();

    }
    cout << m;
    return 0;
}
