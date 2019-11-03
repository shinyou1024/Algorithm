/*
분류 : 시뮬레이션
Q1. 이해부분
	'k년 후' => 나이를 몇 살부터 시작해야할지 애매했음

오답노트
1. 나무죽이기
	한 칸에서 죽는 나무가 하나 나오면 그 뒤로 다 죽여버림 (pop_back)
	문제는 for루프를 짤 때 deque의 사이즈를 종료조건에 넣어버린 것
	pop_back하면서 사이즈도 줄기 때문에 제대로 작동하지 않는다
	=> 미리 사이즈를 변수에 저장해놓고 for loop을 돌리면 됨

2. 봄, 여름을 한 함수에서 돌림
	죽이자마자 양분을 줘서 나무들이 덜 죽게 됨
	=> 분리

3. 시간초과
	나무들의 나이를 저장할 때 deque이 아닌 vector를 쓰고, 죽은 나무들을 안 빼줬더니
	시간초과
	=> deque으로 한 번 sort한 뒤 나무죽이기를 한 큐에 해 줌

*/
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
						age = map[i][j].ages.back();
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
		//for (int i = 1; i <= n; i++) {
			//for (int j = 1; j <= n; j++)
				//cout << map[i][j].ages.size();
				//cout << "\n";
		//}
		//cout << "=================================" << endl;

	}
	cout << m;
	return 0;
}
