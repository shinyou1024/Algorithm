/*
오답노트
1. run(0, 0, 1, 0, 0, 0)을 가정했을 때,
 맨 처음에 호출했을 때 (y, x)와 (sy, sx)가 같아서
 호출되자마자 종료되어버렸다
 => 해당 방향의 다음 칸을 (y, x)로 설정해서 해결
 => 다른 방법으로는 호출횟수를 기록해서 해주는 방법이 있다(그닥 좋은 방법은 아니라고)

 2. 웜홀
  웜홀에 걸렸을 때, 그 다음 웜홀로 이동하는 재귀를 호출하면
  웜홀 if

3. 초기화
한 테스트 케이스가 끝나고
웜홀을 초기화해 주지 않아서 3번 테케까지밖에 정답이 나오지 않았다
*/

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
struct Pos{
	int y, x;
	Pos(int y, int x) : y(y), x(x) {}
};
int n;
int map[110][110];
int ans;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
vector<Pos> wormhole[11];
void init() {
	ans = 0;
	for (int i = 6; i <= 10; i++) {
		wormhole[i].clear();
	}
}
void run(int y, int x, int dir, int score, int sy, int sx);

int main(int argc, char** argv)
{

	int test_case;
	int T;

	//freopen("sample_input.txt", "r", stdin);
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		init();
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
				if (6 <= map[i][j] && map[i][j] <= 10) {
					wormhole[map[i][j]].push_back(Pos(i, j));
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] != 0)
					continue;
				else {
					run(i-1, j, 0, 0, i, j);
					run(i, j+1, 1, 0, i, j);
					run(i+1, j, 2, 0, i, j);
					run(i, j-1, 3, 0, i, j);
				}
			}
		}
		cout << '#' << test_case << ' ' << ans << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}


void run(int y, int x, int dir, int score, int sy, int sx) {
	int num = map[y][x];
	// 종료조건
	if ((y == sy && x == sx) || num == -1) {
		if (score > ans)
			ans = score;
		return;
	}
	int ny=y, nx=x, nd=dir;
	// 벽
	if (y<0 || y>n - 1 || x<0 || x>n - 1) {
		score++;
		if (dir == 0) {
			ny = y + 1;
			nx = x;
			nd = 2;
		}
		else if (dir == 1) {
			ny = y;
			nx = x - 1;
			nd = 3;
		}
		else if (dir == 2) {
			ny = y - 1;
			nx = x;
			nd = 0;
		}
		else if (dir == 3) {
			ny = y;
			nx = x + 1;
			nd = 1;
		}
	}
	// 웜홀
	else if (6 <= num && num <= 10) {
		if (wormhole[num][0].y == y && wormhole[num][0].x == x) {
			ny = wormhole[num][1].y+dy[dir];
			nx = wormhole[num][1].x+dx[dir];
		}
		else {
			ny = wormhole[num][0].y+dy[dir];
			nx = wormhole[num][0].x+dx[dir];
		}
		nd = dir;
	}
	else if (num == 0) {
		ny = y + dy[dir];
		nx = x + dx[dir];
		nd = dir;
	}
	// 블록
	else {
		score++;
		// 상
		if (dir == 0) {
			if (num == 1 || num == 4 || num == 5) {
				ny = y + 1;
				nx = x;
				nd = 2;
			}
			else if (num == 2) {
				ny = y;
				nx = x + 1;
				nd = 1;
			}
			else if (num == 3) {
				ny = y;
				nx = x - 1;
				nd = 3;
			}
		}
		// 우
		else if (dir == 1) {
			if (num == 1 || num == 2 || num == 5) {
				ny = y;
				nx = x - 1;
				nd = 3;
			}
			else if (num == 3) {
				ny = y + 1;
				nx = x;
				nd = 2;
			}
			else if (num == 4) {
				ny = y - 1;
				nx = x;
				nd = 0;
			}
		}
		else if (dir == 2) {
			if (num == 2 || num == 3 || num == 5) {
				ny = y - 1;
				nx = x;
				nd = 0;
			}
			else if (num == 1) {
				ny = y;
				nx = x + 1;
				nd = 1;
			}
			else if (num == 4) {
				ny = y;
				nx = x - 1;
				nd = 3;
			}
		}
		else if (dir == 3) {
			if (num == 3 || num == 4 || num == 5) {
				ny = y;
				nx = x + 1;
				nd = 1;
			}
			else if (num == 1) {
				ny = y - 1;
				nx = x;
				nd = 0;
			}
			else if (num == 2) {
				ny = y + 1;
				nx = x;
				nd = 2;
			}
		}
	}
	run(ny, nx, nd, score, sy, sx);
}
