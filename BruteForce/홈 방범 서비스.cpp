/*

오답노트
1. 범위 체크할 때, y는 체크를 안 해줘서 답이 다르게 나왔다
2.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int ans;
int n, m;
int k;
int total;
int map[21][21];
int dx[] = {-1, 1}; // 왼, 오
void run(int k);
int search(int cnt, int y, int x);
void init() {
	total = 0;
	k = 1;
	ans = 0;
}
int main() {
	//freopen("input.txt", "r", stdin);
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		init();
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
				if (map[i][j])
					total++;
			}
		}

		// 모든 집에 서비스한다고 가정했을 때, 손해가 나지 않을 때까지만
		while ((total*m) >= (2 * k*k - 2 * k + 1)) {
			run(k);
			// 손해가 나지 않고, 더 많은 집을 서비스하면

			k++;
		}

		cout << '#' << tc << ' ' << ans << '\n';
	}
	return 0;
}

void run(int k) {
	// 중심좌표기준
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			int home = 0;
			// 가운데줄
			home += search(k-1, y, x);
			// 위로
			for (int i = 1; i<k; i++) {
				home += search(k-1-i, y - i, x);
			}
			//아래
			for (int i = 1; i<k; i++) {
				home += search(k - 1 - i, y + i, x);
			}

			if (((home*m) >= (2*k*k-2*k+1)) && home>ans) {
				ans = home;
			}
		}
	}
}

int search(int cnt, int y, int x) {
	// 여기!!! : y범위 넘어가는 걸 체크 안 해줌
	if (y<0 || y>n - 1)
		return 0;
	int ret=0;
	// 가운데
	if (map[y][x])
		ret++;
	// 왼쪽
	int nx = x;
	for (int i = 0; i < cnt; i++) {
		nx = nx + dx[0]; // nx를 그냥 nx = x + dx[0] 이렇게 해서 한 칸 밖에 안 갔음
		if (nx<0 || nx>n - 1)
			continue;
		if (map[y][nx])
			ret++;
	}
	nx = x;
	for (int i = 0; i < cnt; i++) {
		nx = nx + dx[1];
		if (nx<0 || nx>n - 1)
			continue;
		if (map[y][nx])
			ret++;
	}
	return ret;
}
