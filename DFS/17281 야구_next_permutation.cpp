/*
오답노트
1. 홈런을 쳤을 때 score++가 한 번밖에 안 됨
	- 1, 2, 3루의 주자들을 신경 안 씀
	- 주자만 득점하는 셈
2. 1을 0으로 잘못 써서 발생한 사소한 실수..
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
int n;
int res[51][10];
int visit[10];
int ans;
int flag = 0;
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


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 9; j++)
			cin >> res[i][j];
	}

	vector<int> v(9);
	for (int i = 0; i < 9; i++) {
		v[i] = i;
	}
	do {
		if (v[3] != 0)
			continue;
		else {
			if (v[0] == 4 && v[1] == 5 && v[2] == 6 && v[3] == 0)
				flag = 1;
			else
				flag = 0;
			run(v);
		}

	} while (next_permutation(v.begin(), v.end()));

	cout << ans;
	return 0;
}
