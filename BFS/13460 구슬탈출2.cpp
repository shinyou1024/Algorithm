/*
*/
#include <iostream>
#include <queue>
using namespace std;
struct Pos {
	int y, x;
	Pos(int y, int x) :y(y), x(x) {};
	Pos() {};
};
struct State {
	Pos red, blue;
	State(Pos red, Pos blue) : red(red), blue(blue) {};
	State() {};
};
int h, w;
char map[15][15];
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
int ans = 11;
Pos blue, red;
int vist[15][15];
char which_front(int dir, int ry, int rx, int by, int bx) {
	if (dir == 0) {
		if (ry < by) return 'R';
		else return 'B';
	}
	else if (dir == 1) {
		if (rx > bx) return 'R';
		else return 'B';
	}
	else if (dir == 2) {
		if (ry > by) return 'R';
		else return 'B';
	}
	else if (dir == 3) {
		if (rx < bx) return 'R';
		else return 'B';
	}
}
void dfs(int dir, int cnt, int ry, int rx, int by, int bx) {
	if (cnt > 10) return;
	if (dir == 0 || dir == 2) {
		char front = 'B';
		if (rx == bx) {
			front = which_front(dir, ry, rx, by, bx);

		}

		if (front == 'B') {
			int ny = by; int nx = bx;
			while (true) {
				ny = ny + dy[dir];
				nx = nx + dx[dir];
				if (map[ny][nx] != '#') {
					if (map[ny][nx] == 'O') return;
					by = ny;
					bx = nx;
				}
				else break;
			}
			ny = ry; nx = rx;
			while (true) {
				ny = ny + dy[dir];
				nx = nx + dx[dir];
				if (map[ny][nx] != '#') {
					if (map[ny][nx] == 'O') {
						ans = cnt < ans ? cnt : ans;
						return;
					}
					if (!(ny == by && nx == bx)) {
						ry = ny;
						rx = nx;
					}
					else break;
				}
				else break;
			}
		}

		else {
			int ny = ry; int nx = rx;
			while (true) {
				ny = ny + dy[dir];
				nx = nx + dx[dir];
				if (map[ny][nx] != '#') {

					ry = ny;
					rx = nx;
				}
				else break;
			}

			ny = by; nx = bx;
			while (true) {
				ny = ny + dy[dir];
				nx = nx + dx[dir];
				if (map[ny][nx] != '#') {
					if (map[ny][nx] == 'O') return;
					if (!(ny == ry && nx == rx)) {
						by = ny;
						bx = nx;
					}
					else break;
				}
				else break;
			}
			if (map[ry][rx] == 'O') {
				ans = cnt < ans ? cnt : ans;
				return;
			}
		}

	}

	if (dir == 1 || dir == 3) {
		char front = 'B';
		if (ry == by) {
			front = which_front(dir, ry, rx, by, bx);

		}

		if (front == 'B') {
			int ny = by; int nx = bx;
			while (true) {
				ny = ny + dy[dir];
				nx = nx + dx[dir];
				if (map[ny][nx] != '#') {
					if (map[ny][nx] == 'O') return;
					by = ny;
					bx = nx;
				}
				else break;
			}
			ny = ry; nx = rx;
			while (true) {
				ny = ny + dy[dir];
				nx = nx + dx[dir];
				if (map[ny][nx] != '#') {
					if (map[ny][nx] == 'O') {
						ans = cnt < ans ? cnt : ans;
						return;
					}
					if (!(ny==by && nx==bx)) {
						ry = ny;
						rx = nx;
					}
					else break;
				}
				else break;
			}
		}

		else {
			int ny = ry; int nx = rx;
			while (true) {
				ny = ny + dy[dir];
				nx = nx + dx[dir];
				if (map[ny][nx] != '#') {

					ry = ny;
					rx = nx;
				}
				else break;
			}
			ny = by; nx = bx;
			while (true) {
				ny = ny + dy[dir];
				nx = nx + dx[dir];
				if (map[ny][nx] != '#') {
					if (map[ny][nx] == 'O') return;
					if ((!(ny == ry && nx == rx))) {
						by = ny;
						bx = nx;
					}
					else break;
				}
				else break;
			}
			if (map[ry][rx] == 'O') {
				ans = cnt < ans ? cnt : ans;
				return;
			}
		}
	}

	for (int i = 0; i < 4; i++) {
		if (i == dir) continue;
		if (i == (dir + 2) % 4) continue;
		dfs(i, cnt + 1, ry, rx, by, bx);
	}
}



int main() {
	cin >> h >> w;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'R') {
				red.y = i; red.x = j;
				map[i][j] = '.';
			}
			if (map[i][j] == 'B') {
				blue.y = i; blue.x = j;
				map[i][j] = '.';
			}
		}
	}
	for (int i = 0; i < 4; i++) {
		dfs(i, 1, red.y, red.x, blue.y, blue.x);
	}
	if (ans == 11) cout << -1;
	else cout << ans;
	return 0;
}
