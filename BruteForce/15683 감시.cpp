#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
using namespace std;
struct Pos{
	int y, x, d;
	Pos(int y, int x) : y(y), x(x) {}
};

int n, m;
int map[10][10];
vector<int> direction; // 벡터에 있는 cctv순으로 각자의 방향이 저장
vector<Pos> cctv;
int visit[10][10];
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
int tmp[10][10];
int ans=987654321; // 감시 가능영역

void check(int y, int x, int d) {

	int ny = y + dy[d];
	int nx = x + dx[d];

	if (ny<0 || ny>n - 1 || nx<0 || nx>m - 1) return;
	if (map[ny][nx] == 6) {
		return;
	}

	if (map[ny][nx]==0) {
		tmp[ny][nx] = 10;
		check(ny, nx, d);
	}

	if (1 <= map[ny][nx] && map[ny][nx] <= 5) {
		check(ny, nx, d);
	}
}

void dfs(int depth) {
	if (depth == cctv.size()) {
		memcpy(tmp, map, sizeof(map));
		for (int i = 0; i < cctv.size(); i++) {

			int y = cctv[i].y;
			int x = cctv[i].x;
			int d = direction[i];
			int id = map[y][x];
			switch (id) {
			case 1:
				check(y, x, d);
				break;
			case 2:
				check(y, x, d);
				check(y, x, (d + 2) % 4);
				break;
			case 3:
				check(y, x, d);
				check(y, x, (d + 1) % 4);
				break;
			case 4:
				check(y, x, d);
				check(y, x, (d + 1) % 4);
				check(y, x, (d + 3) % 4);
				break;
			case 5:
				for (int i = 0; i < 4; i++) {
					check(y, x, i);
				}
				break;
			}
		}
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (tmp[i][j] == 0)
					cnt++;
			}
		}

		ans = cnt < ans ? cnt : ans;
		return;
	}

	for (int i = 0; i < 4; i++) {
		direction.push_back(i);
		dfs(depth + 1);
		direction.pop_back();
	}
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (1 <= map[i][j] && map[i][j] <= 5)
				cctv.push_back(Pos(i, j));
		}
	}

	dfs(0);

	cout << ans;
	return 0;
}
