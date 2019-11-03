/*
오답노트
1. 장애물을 고려하지 않았음
*/
#include<iostream>
#include<string.h>
#include<queue>
using namespace std;

struct Info {
	int y;
	int x;
	int dist; //현재까지의 이동거리
	int cnt; //말처럼 뛴 횟수

	Info(int a, int b, int c, int d) {
		y = a;
		x = b;
		dist = c;
		cnt = d;
	}
	// 빈생성자를 같이 만들면 좋다
	Info() {}
};
int k, w, h;
int map[210][210];
int visit[210][210][40]; // 말처럼 뛴 횟수가 n번 일 때 y, x를 방문했는가
//int dist[210][210];
int hy[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };
int hx[8] = { -2, -1, 1, 2, -2, -1, 1, 2 };
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

int BFS() {
	queue<Info> q;
	q.push(Info(0,0,0,0));
	visit[0][0][0] = 1;

	while (!q.empty()) {
		Info now = q.front();
		q.pop();

		if (now.y == h - 1 && now.x == w - 1)
			return now.dist;

		for (int i = 0; i < 4; i++) {
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];

			if (0 <= ny && ny < h && 0 <= nx && nx < w) {
				if (!visit[ny][nx][now.cnt] && map[ny][nx]!=1) {
					visit[ny][nx][now.cnt] = 1;
					q.push(Info(ny, nx, now.dist + 1, now.cnt));
				}
			}
		}

		// 말처럼 뛸 수 있는 횟수가 남아있으면
		if (now.cnt < k) {
			for (int i = 0; i < 8; i++) {
				int ny = now.y + hy[i];
				int nx = now.x + hx[i];

				if (0 <= ny && ny < h && 0 <= nx && nx < w) {
					if (!visit[ny][nx][now.cnt + 1] && map[ny][nx] != 1) {
						visit[ny][nx][now.cnt + 1] = 1;
						q.push(Info(ny, nx, now.dist + 1, now.cnt + 1));
					}
				}
			}
		}
	}

	// 다 돌렸는데도 도착 못 함
	return -1;
}

int main() {
	cin >> k;

	cin >> w >> h;
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			cin >> map[i][j];

	memset(visit, 0, sizeof(visit));
	cout<<BFS();

	return 0;
}
