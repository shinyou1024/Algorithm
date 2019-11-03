#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <queue>
using namespace std;
struct State{
	int y;
	int x;
	int t;
	vector<int> key;
	State(int y, int x, int t) : y(y), x(x), t(t) {}
};
int w, h;
int sy, sx;
char map[51][51];
int visit[51][51][250];
int ans;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

bool hasKey(char C, vector<int> v) {
	if (v.size() == 0)
		return false;
	for (int i = 0; i < v.size(); i++) {
		if (v[i] - 32 == C)
			return true;
	}
	return false;
}


int bfs() {
	queue<State> q;
	visit[sy][sx][0] = 1;
	q.push(State(sy, sx, 0));

	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		int t = q.front().t;
		vector<int> key = q.front().key;

		q.pop();
		if ('a' <= map[y][x] && map[y][x] <= 'f') {
			key.push_back(map[y][x]);
		}
		if (map[y][x] == '1') {
			return t;
		}
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny<0 || ny>h - 1 || nx<0 || nx>w - 1)
				continue;
			if (visit[ny][nx][key.size()])
				continue;
			if (map[ny][nx] == '#')
				continue;
			if ('A' <= map[ny][nx] && map[ny][nx] <= 'F') {
				if (hasKey(map[ny][nx], key)) {
					q.push(State(ny, nx, t + 1));
					visit[ny][nx][key.size()] == 1;
				}
			}
			else {
				q.push(State(ny, nx, t + 1));
				visit[ny][nx][key.size()] == 1;
			}
		}
	}
	return -1;
}
int main() {

	cin >> h >> w;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> map[i][j];
			if (map[i][j] == '0') {
				sy = i;
				sx = j;
			}
		}
	}
	cout << bfs();

	return 0;
}
