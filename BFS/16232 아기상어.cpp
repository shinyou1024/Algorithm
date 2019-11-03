/*
오답노트
1. 상어가 원래 위치했던 자리를 0으로 안 바꿔줬다
	그래서 시뮬돌릴 때 그 자리를 지나치지 못하고 돌아가게 됨
*/
#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
struct Pos{
	int y, x, t;
	Pos(int y, int x, int t) : y(y), x(x), t(t) {};
	Pos() {};
};
int n;
int sy, sx;
int cy, cx;
int map[25][25];
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
int ans;
int size = 2;
int cnt;
int visit[25][25];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				sy = i, sx = j;
				map[sy][sx] = 0;
			}
		}
	}

	while (true) {
		// 탐색
		memset(visit, 0, sizeof(visit));
		queue<Pos> fish;
		queue<Pos> q;
		visit[sy][sx] = 1;
		q.push(Pos(sy, sx, 0));
		int Min = 9999;
		while (!q.empty()) {
			int y = q.front().y;
			int x = q.front().x;
			int t = q.front().t;

			q.pop();
			if (t > Min) continue;
			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];

				if (ny<0 || ny>n - 1 || nx<0 || nx>n - 1) continue;
				if (map[ny][nx]>size) continue;
				if (visit[ny][nx]) continue;
				// x좌표 비교해서 물고기 갱신
				if (map[ny][nx] && map[ny][nx] < size) {
					if (t + 1 <= Min) {
						fish.push(Pos(ny, nx, t + 1));
					}
				}
				visit[ny][nx] = 1;
				q.push(Pos(ny, nx, t + 1));
			}
		}
		// 잡아먹기
		if (fish.empty()) {
			cout << ans;
			break;
		}
		else {
			int fy, fx, ftime;
			fy = fish.front().y; fx = fish.front().x; ftime = fish.front().t;
			fish.pop();
			while (!fish.empty()) {
				if (ftime > fish.front().t) {
					fy = fish.front().y; fx = fish.front().x; ftime = fish.front().t;
				}
				else if (ftime == fish.front().t) {
					if (fy > fish.front().y) {
						fy = fish.front().y; fx = fish.front().x; ftime = fish.front().t;
					}
					else if (fy == fish.front().y) {
						if (fx > fish.front().x) {
							fy = fish.front().y; fx = fish.front().x; ftime = fish.front().t;
						}
					}
				}
				fish.pop();
			}
			cnt++;
			if (cnt == size) {
				size++;
				cnt = 0;
			}
			map[fy][fx] = 0;
			sy = fy; sx = fx;
			ans += ftime;
		}


	}
	return 0;
}
