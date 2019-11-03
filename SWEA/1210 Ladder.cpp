#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int T;
int map[101][101];
int dy[] = { -1, 0, 0 };
int dx[] = { 0, -1, 1 };
int y, x;

int change(int b, int a, int d) {
	while (map[b - 1][a] == 0) {
		a = a + dx[d];
	}

	return a;
}


int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "r", stdin);

	for (int tc = 1; tc <= 10; tc++) {
		cin >> T;
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				cin >> map[i][j];
				if (map[i][j] == 2) {
					y = i;
					x = j;
				}
			}
		}
		while (1) {
			// 0번째줄에 도달했으면 종료
			if (y == 0) {
				cout << '#' << tc << ' ' << x <<'\n';
				break;
			}

			// 방향 전환
			if (map[y][x - 1] == 1) {
				x = change(y, x - 1, 1);
			}
			else if (map[y][x + 1] == 1) {
				x = change(y, x + 1, 2);
			}
			// 위로
			if (map[y - 1][x] == 1) {
				y = y + dy[0];
				x = x + dx[0];
			}
			//cout << y << ',' << x << endl;
		}



	}

	return 0;
}
