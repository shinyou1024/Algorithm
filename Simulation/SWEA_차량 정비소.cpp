#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
#include <algorithm>
using namespace std;


struct CS{
	int idx;
	int arrive;
	int a, b;
	CS(int idx, int arrive) :idx(idx), arrive(arrive) {};
	CS(int idx, int arrive, int a) :idx(idx), arrive(arrive), a(a) {};
	CS() {};
};

int n, m, k, A, B;
int js[10];
int jb[10];
int ans;
int av1[10];
int av2[10];
queue<CS> wait1;
vector<CS> wait2;

bool op(CS a, CS b) {
	if (a.arrive > b.arrive) {
		return true;
	}
	else if (a.arrive == b.arrive) {
		if (a.a > b.a) return true;
		else return false;
	}
	else return false;
}
void init() {
	for (int i = 1; i <= n; i++) {
		av1[i] = 0;
		av2[i] = 0;
	}
	ans = 0;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("sample_input.txt", "r", stdin);
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> n >> m >> k >> A >> B;
		for (int i = 1; i <= n; i++) {
			cin >> js[i];
		}
		for (int i = 1; i <= m; i++) {
			cin >> jb[i];
		}
		for (int i = 1; i <= k; i++) {
			int t1;
			cin >> t1;
			wait1.push(CS(i, t1));
		}
		init();
		int t = 0;

		while (!wait1.empty() || !wait2.empty()) {
			//cout << t << "초 : ";
			// 도착한 사람 중 기다리는 사람이 있는가
			while (!wait1.empty() && wait1.front().arrive<=t) {
				CS first = wait1.front();
				int flag = 0;
				// 빈 자리가 있는가
				for (int i = 1; i <= n; i++) {
					if (av1[i] <= t) {
						// 그 다음 대기줄
						wait2.push_back(CS(first.idx, t + js[i], i));
						//cout << first.idx << "->" << i << "접수창구" << ' ';
						wait1.pop();
						// av1갱신
						av1[i] = t + js[i]; // 부터 사용가능!
						flag = 1;
						break;
					}
				}
				if (flag == 0) break; //t초에 비어있는 애가 없을 경우
			}

			// 정렬
			sort(wait2.begin(), wait2.end(), op);
			// 정비 기다리는 애들 처리
			while (!wait2.empty() && wait2[wait2.size() - 1].arrive <= t) {
				CS first = wait2[wait2.size() - 1];
				int flag = 0;
				for (int i = 1; i <= m; i++) {
					if (av2[i]<=t && first.arrive <= t) {
						if (first.a == A && i == B) {
							ans += first.idx;
						}
						//cout << first.idx << "->" << i << "정비창구" << ' ';
						av2[i] = t + jb[i];
						flag = 1;
						wait2.pop_back();
						break;
					}
				}
				if (flag == 0) break;
			}
			//cout << endl;
			t++;
		}
		if (ans == 0) cout << '#' << tc << ' ' << -1 << '\n';
		else cout << '#' << tc << ' ' << ans << '\n';
	}
	return 0;
}
