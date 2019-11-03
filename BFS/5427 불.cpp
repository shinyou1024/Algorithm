/*
오답노트
1. 시간초과
  - 처음에는 불이 있는 모든 칸에 대해 각각 bfs_fire()을 돌렸다.
  - 해결
  visit 배열을 각각의 bfs에 대해 두지 않고, 불이 번지는 시간을 기록하는 fire배열을 전역변수로 두고 각 칸에 대해 bfs_fire()을 돌린다
  fire 배열은 -1로 초기화 되어 있는데 처음 방문한 경우엔 그냥 시간을 기록한다
  이미 값이 있는 칸은 그 값과 비교해서 더 빨리 방문하는 경우(더 빨리 번지는 경우)에만 큐에 넣고 탐색을 한다

2. 로직 실수 : bfs_escape
  97번째 줄 if (fire[ny][nx] > time || fire[ny][nx]==-1)
  bfs_fire()에서 불이 아예 번지지 않는 칸은 -1로 되어 있다
  if문의 두 번째 조건을 추가하지 않으면 불이 번지지 않는 칸으로 가지 않는다!



*/
#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
struct Pos{
	int y;
	int x;
	int t;
	Pos(int y, int x, int t) : y(y), x(x), t(t) {}
};
int T, w, h;
char map[1000 + 1][1000 + 1];
int fire[1000 + 1][1000 + 1];
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
int ans;
void init() {
	memset(fire, -1, sizeof(fire));
	ans = -1;
}
void bfs_fire(int y, int x) {
	queue<Pos> q;

	q.push(Pos(y, x, 0));
	fire[y][x] = 0;

	while (!q.empty()) {
		y = q.front().y;
		x = q.front().x;
		int t = q.front().t;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny<0 || ny>h - 1 || nx<0 || nx>w - 1)
				continue;
			if (map[ny][nx] == '#' || map[ny][nx] == '*')
				continue;
			if (fire[ny][nx]==-1 || t+1 < fire[ny][nx]) {
				fire[ny][nx] = t + 1;
				q.push(Pos(ny, nx, t + 1));
			}

		}
	}

}
int bfs_escape(int y, int x) {
	queue<Pos> q;
	int visit[1000 + 1][1000 + 1];
	memset(visit, 0, sizeof(visit));

	q.push(Pos(y, x, 0));
	visit[y][x] = 1;
	while (!q.empty()) {
		y = q.front().y;
		x = q.front().x;
		int t = q.front().t;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			int time = t + 1;

			// 탈출

			if (ny<0 || ny>h - 1 || nx<0 || nx>w - 1) {
				return time;
			}
			if (visit[ny][nx])
				continue;
			if (map[ny][nx] == '#')
				continue;
			if (map[ny][nx] == '*')
				continue;
			// 중요!!! bfs_fire()에서 불이 아예 번지지 않는 칸은 -1로 되어 있다
			// if문의 두 번째 조건을 추가하지 않으면 불이 번지지 않는 칸으로 가지 않는다!
			if (fire[ny][nx] > time || fire[ny][nx]==-1) {
				visit[ny][nx] = 1;
				q.push(Pos(ny, nx, time));
			}

		}
	}
	return -1;
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> T;
	for (int tc = 0; tc < T; tc++) {
		init();
		cin >> w >> h;
		int sy, sx;
		queue<pair<int, int> > f;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> map[i][j];
				if (map[i][j] == '@') {
					sy = i;
					sx = j;
				}
				if (map[i][j] == '*') {
					f.push(make_pair(i, j));
				}
			}
		}
		while (!f.empty()) {
			bfs_fire(f.front().first, f.front().second);
			f.pop();
		}

		ans = bfs_escape(sy, sx);
		if (ans == -1)
			cout << "IMPOSSIBLE" << '\n';
		else
			cout << ans << '\n';
	}
	return 0;
}
