#include <iostream>
#include <queue>
using namespace std;
struct Pos{
	int y;
	int x;
	Pos(int y, int x) : y(y), x(x) {}
};
int n, m;
int map[52][52];
int dy[] = { 0, -1, 0, 1 }; // 서북동남 순
int dx[] = { -1, 0, 1, 0 };

int room_num[52][52];
int area[50 * 50+1]; // 각 방의 넓이
int rooms;
int ans2;
int ans3;

int bfs(int y, int x, int num);

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	// 방의 개수 세면서 방의 번호 기록
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (room_num[i][j] == 0) {
				rooms++;
				area[rooms] = bfs(i, j, rooms);
			}
			if (ans2 < area[rooms])
				ans2 = area[rooms];
		}
	}

	// 각 칸의 벽을 없애보면서 새로운 방 만들기
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			for (int k = 0; k < 4; k++) {
				if (map[y][x] & (1 << k)) {
					int ny = y + dy[k];
					int nx = x + dx[k];
					if (ny<0 || ny>n - 1 || nx<0 || nx>m - 1)
						continue;
					// 각 방의 번호
					int num1 = room_num[y][x];
					int num2 = room_num[ny][nx];
					if (num1 == num2)
						continue;
					if (ans3 < area[num1] + area[num2])
						ans3 = area[num1] + area[num2];
				}
			}
		}
	}

	cout << rooms << '\n';
	cout << ans2 << '\n';
	cout << ans3;
	return 0;
}

int bfs(int y, int x, int num) {
	queue<Pos> q;
	q.push(Pos(y, x));
	room_num[y][x] = num;

	int cnt = 0; // 방의 넓이
	while (!q.empty()) {
		y = q.front().y;
		x = q.front().x;
		q.pop();
		cnt++;
		for (int i = 0; i < 4; i++) {
			if (map[y][x] & (1 << i)) // 비트연산해서 0이 아니면 그 방향에 벽이 있음
				continue;
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny<0 || ny >n - 1 || nx <0 || nx>m - 1)
				continue;
			if (room_num[ny][nx]!=0)
				continue;

			q.push(Pos(ny, nx));
			room_num[ny][nx] = num;
		}
	}
	return cnt;
}
