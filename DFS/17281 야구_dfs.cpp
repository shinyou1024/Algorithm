#include <iostream>
#include <vector>
using namespace std;
int n;
int res[51][10];
int visit[10];
int ans;
void run(vector<int> order) {
  int base[3]; // 0이 1루
	memset(base, 0, sizeof(base));
	int now = 0; //몇번째타자인지
	int score = 0;
	int out = 0;
	int inning = 0;
	while (inning < n) {
		int man = order[now]; // 현재 칠 선수 번호
		int result = res[inning][man];
		now = (now + 1) % 9;

		if (result == 1) {
			if (base[2] == 1) {
				score++;
				base[2] = 0;
			}
			if (base[1] == 1) {
				base[2] = 1;
				base[1] = 0;
			}
			if (base[0] == 1) {
				base[1] = 1;
				base[0] = 0;
			}
			base[0] = 1;

		}
		else if (result == 2) {
			if (base[2] == 1) {
				score++;
				base[2] = 0;
			}
			if (base[1] == 1) {
				score++;
				base[1] = 0;
			}
			if (base[0] == 1) {
				base[2] = 1;
				base[0] = 0;
			}
			base[1] = 1;
		}
		else if (result == 3) {
			if (base[2] == 1) {
				score++;
				base[2] = 0;
			}
			if (base[1] == 1) {
				score++;
				base[1] = 0;
			}
			if (base[0] == 1) {
				score++;
				base[0] = 0;
			}
			base[2] = 1;
		}
		else if (result == 4) {
			score++;
			for (int i = 0; i < 3; i++) {
				if (base[i])
					score++;
			}
			memset(base, 0, sizeof(base));
		}
		else if (result == 0) {
			out++;
		}

		if (out == 3) {
			out = 0;
			memset(base, 0, sizeof(base));
			inning++;
		}

	}

	if (score > ans)
		ans = score;

}
void dfs(int depth, vector<int> v) {
	if (depth == 9) {
		run(v);
		return;
	}

	for (int i = 1; i < 9; i++) {
		if (visit[i])
			continue;
		if (depth == 3) {
			v.push_back(0);
			dfs(depth + 1, v);
			v.pop_back();
		}
		else {
			v.push_back(i);
			visit[i] = 1;
			dfs(depth + 1, v);
			v.pop_back();
			visit[i] = 0;
		}

	}
}


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 9; j++)
			cin >> res[i][j];
	}

	vector<int> v;
	dfs(0, v);
	cout << ans;
	return 0;
}
