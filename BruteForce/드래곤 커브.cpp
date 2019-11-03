/*
오답노트
1. 시작점 다음 좌표까지 표시해줘야 하는데 안 해줌
2. dragon_curve()를 돈 후 y좌표와 x좌표가 바뀌지 않는다
	=> 전역변수로 선언해줘서 해결
*/
#include <iostream>
#include <vector>
using namespace std;
int n;
int map[101][101];
int dy[] = { 0, -1, 0, 1 };
int dx[] = { 1, 0, -1, 0 };
vector<int> history;
int y, x;
void dragon_curve(int g) {
	for (int i = history.size() - 1; i >= 0; i--) {
		int d = (history[i]+1)%4;
		y = y + dy[d];
		x = x + dx[d];
		map[y][x] = 1;
		history.push_back(d);
	}

}

int isSquare(int y, int x) {
	if (map[y][x + 1] && map[y + 1][x] && map[y + 1][x + 1]) return 1;
	else return 0;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int d, g;
		cin >> x >> y >> d >> g;
		map[y][x] = 1;
		y = y + dy[d]; x = x + dx[d];
		map[y][x] = 1;

		history.push_back(d);
		for (int j = 1; j <= g; j++) {
			dragon_curve(j);
		}
		history.clear();
	}
	int ans=0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (map[i][j]) {
				ans += isSquare(i, j);
			}
		}
	}
	cout << ans;
	return 0;
}
