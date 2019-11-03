#define _CRT_SECURE_NO_WARNINGS
#define INF 987654321
#include <iostream>
#include <queue>
#include <vector>
#include <math.h>
#include <string.h>
#include <algorithm>
using namespace std;
struct Pos{
	int y, x;
	int t1, t2;
	int min;
	Pos(int y, int x) :y(y), x(x) {};
	Pos() {};
};

int n;
int map[15][15];
vector<Pos> stair;
vector<Pos> p;
int visit[15];
vector<int> s1;
vector<int> s2;
int ans = INF;
void init() {
	stair.clear();
	p.clear();
	ans = INF;
}

void run() {
	int time = 0;

	sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());
	queue<int> w1; queue<int> w2;
	for (int i = 0; i < s1.size(); i++) {
		w1.push(s1[i]);
	}
	for (int i = 0; i < s2.size(); i++) {
		w2.push(s2[i]);
	}
	queue<int> q1; queue<int> q2;
	while (!q1.empty() || !q2.empty() || !w1.empty() || !w2.empty()) {
		time++;
		if (time > ans) return;
		//cout << time << "초 | ";
		// 계단 비우기
		while (!q1.empty() && q1.front() == time) {
			q1.pop();
			while (!w1.empty() && w1.front() < time) {
				if (q1.size() < 3) {
					q1.push(time + map[stair[0].y][stair[0].x]);
					w1.pop();
				}
				else break;
			}

		}

		while (!q2.empty() && q2.front() == time) {
			q2.pop();
			while (!w2.empty() && w2.front() < time) {
				if (q2.size() < 3) {
					q2.push(time + map[stair[1].y][stair[1].x]);
					w2.pop();
				}
				else break;
			}
		}
		while (!w1.empty() && w1.front() <= time) {
			if (q1.size() < 3) {
				q1.push(time + 1 + map[stair[0].y][stair[0].x]);
				w1.pop();
			}
			else break;
		}
		while (!w2.empty() && w2.front() <= time) {
			if (q2.size() < 3) {
				q2.push(time + 1 + map[stair[1].y][stair[1].x]);
				w2.pop();
			}
			else break;
		}
		// 대기하다가 계단으로 진입


		if (q1.empty() && q2.empty() && w1.empty() && w2.empty()) break;
		//cout << "계단1 : " << q1.size() << " 계단2 : " << q2.size() << endl;
	}
	ans = time;

}


void dfs(int depth, int r, int x) {
	if (depth == r) {
		for (int i = 0; i < p.size(); i++) {
			if (visit[i] == 1) {
				s1.push_back(p[i].t1);
			}
			else {
				s2.push_back(p[i].t2);
			}
		}
		run();
		s1.clear(); s2.clear();
		return;
	}
	for (int i = x; i < p.size(); i++) {
		if (visit[i]) continue;
		visit[i] = 1;
		dfs(depth + 1, r, i + 1);
		visit[i] = 0;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("sample_input.txt", "r", stdin);
	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
				if (map[i][j]>1) {
					stair.push_back(Pos(i, j));
				}
				if (map[i][j] == 1) {
					p.push_back(Pos(i, j));
				}
			}
		}

		// 거리 계산
		for (int i = 0; i < p.size(); i++) {
			p[i].t1 = abs(p[i].y - stair[0].y) + abs(p[i].x - stair[0].x);
			p[i].t2 = abs(p[i].y - stair[1].y) + abs(p[i].x - stair[1].x);
		}


		for (int i = 0; i <= p.size(); i++) {
			dfs(0, i, 0);
		}
		cout << '#' << test_case << ' ' << ans << '\n';
		init();
	}
	return 0;
}
