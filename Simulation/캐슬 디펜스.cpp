/*
1. 맵 초기화해주기
다 죽인 맵으로 그 다음 dfs를 돌렸다
2. 다른 궁수가 같은 애 죽일 때
카운팅이 두 번되었다. 한 번만 카운팅되게 하니 통과!
*/
#include <iostream>
#include <vector>
#include <math.h>
#include <string.h>
#include <algorithm>
using namespace std;
struct Pos {
	int y, x, d;
	Pos(int y, int x, int d) :y(y), x(x), d(d) {}
};

int n, m, d;
int map[17][17];
int original[17][17];
int visit[15];
int ans;
vector<int> position;
vector<Pos> dead;
void find_enemy(int y, int x, int t);
int attack();
void dfs(int depth, int x);

int main() {
	cin >> n >> m >> d;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cin >> original[i][j];
	}

	dfs(0, 0);
	cout << ans;
	return 0;
}

// 조합
void dfs(int depth, int x) {

	if (depth == 3) {
		memcpy(map, original, sizeof(map));
		int now = attack();
		ans = now > ans ? now : ans;

		return;
	}

	for (int i = x; i < m; i++) {
		if (visit[i])
			continue;
		visit[i] = 1;
		position.push_back(i);
		dfs(depth + 1, x + 1);
		visit[i] = 0;
		position.pop_back();
	}
}

// 0번째 줄에 있는 적들이 성에 도착할 때까지
int attack() {
	int ret = 0;
	for (int t = 0; t < n; t++) {
		for (int i = 0; i < 3; i++) {
			int p = position[i]; // p번째 열
			find_enemy(n - t, p, t); // 적 죽였으면 +1, 죽일 애 없으면 +0
		}

		int check[22][22];
		memset(check, 0, sizeof(check));
		for (int k = 0; k < dead.size(); k++) {
			if (check[dead[k].y][dead[k].x]) continue;
			else {
				check[dead[k].y][dead[k].x] = 1;
				ret++;
				map[dead[k].y][dead[k].x] = 0;
			}
		}
		dead.clear();
	}
	return ret;
}

// 궁수 한 명마다 적 찾기
void find_enemy(int y, int x, int t) {
	vector<Pos> v;
	for (int i = n - 1 - t; i >= 0; i--) {
		for (int j = 0; j < m; j++) {
			int dist = abs(y - i) + abs(x - j);
			if (map[i][j] == 1 && dist <= d) {
				v.push_back(Pos(i, j, dist));
			}
		}
	}
	// 죽일 애 없음
	if (v.empty())
		return;



	// 비교
	int target = 0;
	for (int i = 1; i < v.size(); i++) {
		if (v[i].d < v[target].d)
			target = i;
		else if (v[i].d == v[target].d) {
			if (v[i].x < v[target].x)
				target = i;
		}
	}
	// 죽이고 1리턴
	dead.push_back(Pos(v[target].y, v[target].x, v[target].d));

}
