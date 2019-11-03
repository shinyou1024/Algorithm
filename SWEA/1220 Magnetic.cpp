#include <iostream>
#include <algorithm>
using namespace std;
int n;
int map[101][101];
int ans;

void init() {
	ans = 0;
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	for (int tc = 1; tc <= 10; tc++) {
		init();
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
			}
		}

		// 떨어지는 것 없애주기
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[j][i] == 1)
					break;
				if (map[j][i] == 2) {
					map[j][i] = 10;
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = n - 1; j >= 0; j--) {
				if (map[j][i] == 2)
					break;
				if (map[j][i] == 1) {
					map[j][i] = 0;
				}
			}
		}

		// 교착 상태 확인
		for (int i = 0; i < n; i++) {
			int N = 0;
			int S = 0;
			for (int j = 0; j < n; j++) {
				if (map[j][i] == 1)
					N++;
				if (map[j][i] == 2)
					S++;
			}
			ans += min(N, S);
		}

		cout << '#' << tc << ' ' << ans << '\n';
	}

	return 0;
}
