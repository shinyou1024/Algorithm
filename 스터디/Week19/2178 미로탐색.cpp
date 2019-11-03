#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;

int n, m;
int map[110][110];
int visit[110][110];
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

struct Pos{
	Pos(int y, int x, int dist) : x(x), y(y), dist(dist) {}
	int y;
	int x;
	int dist;
};
int BFS();

int main() {

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			scanf("%1d", &map[i][j]);
	}


	cout << BFS();

	return 0;
}


int BFS() {
	queue<Pos> q;
	int y = 0;
	int x = 0;
	visit[0][0] = 1;
	q.push(Pos(y, x, 1));

	while (!q.empty()) {
		x = q.front().x;
		y = q.front().y;
		int d = q.front().dist;
		if (y == n - 1 && x == m - 1)
			return d;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny<0 || ny>n - 1 || nx<0 || nx>m - 1)
				continue;
			if (map[ny][nx] == 0)
				continue;
			if (visit[ny][nx])
				continue;

			q.push(Pos(ny, nx, d+1));
			visit[ny][nx] = 1;
		}

	}
}
