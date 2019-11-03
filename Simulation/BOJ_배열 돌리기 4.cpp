#define _CRT_SECURE_NO_WARNINGS
#define INF 987654321
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
struct Op{
	int r, c, s;
	Op(int r, int c, int s) :r(r), c(c), s(s) {};
};
int h, w, k;
int origin[55][55];
int map[55][55];
int prv[55][55];
int visit[10];
int order[10];
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
vector<Op> op;
int ans = INF;
void cal() {
	int ret = INF;
	for (int i = 1; i <= h; i++) {
		int sum = 0;
		for (int j = 1; j <= w; j++) {
			sum += map[i][j];
		}
		if (sum < ret) {
			ret = sum;
		}
	}

	if (ret < ans) {
		ans = ret;
	}
}
void rotate(int r, int c, int s) {
	while (s > 0) {
		int len = 2 * s + 1;
		int up = r - s; int down = r + s; int right = c + s; int left = c - s;
		int tmp = map[up][left];
		// 아래로
		int y = up; int x = left;
		for (int i = 1; i < len; i++) {
			y = y + dy[2]; x = x + dx[2];
			map[y - 1][x] = map[y][x];
		}

		// 오른쪽
		for (int i = 1; i < len; i++) {
			y = y + dy[1]; x = x + dx[1];
			map[y][x - 1] = map[y][x];
		}

		for (int i = 1; i < len; i++) {
			y = y + dy[0]; x = x + dx[0];
			map[y + 1][x] = map[y][x];
		}

		for (int i = 1; i < len-1; i++) {
			y = y + dy[3]; x = x + dx[3];
			map[y][x + 1] = map[y][x];
		}

		map[y][x] = tmp;
		s--;
	}

}
void print() {
	cout << "=======================" << endl;
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			cout << map[i][j] << ' ';
		}
		cout << endl;
	}
}
void dfs(int depth) {
	if (depth == k) {
		for (int i = 0; i < k; i++) {
			rotate(op[order[i]].r, op[order[i]].c, op[order[i]].s);
		}
		cal();
		//print();
		memcpy(map, origin, sizeof(map));
		return;
	}

	for (int i = 0; i < k; i++) {
		if (visit[i]) continue;
		visit[i] = 1;
		order[depth] = i;
		//print();
		dfs(depth + 1);
		visit[i] = 0;

	}
}

int main(int argc, char** argv)
{

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("sample_input.txt", "r", stdin);
	cin >> h >> w >> k;
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			cin >> origin[i][j];
		}
	}
	memcpy(map, origin, sizeof(origin));
	for (int i = 0; i < k; i++) {
		int y, x, s;
		cin >> y >> x >> s;
		op.push_back(Op(y, x, s));
	}

	dfs(0);
	cout << ans;
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
