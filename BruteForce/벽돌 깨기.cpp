/*
오답노트
1. dfs 돌릴 때 가로 길이가 12보다 작을 때도 0부터 12까지 고르게 함..
	=> 시간초과
	for (int i = 0; i < 12; i++) {
		order[depth] = arr[i];
		dfs(depth + 1);
	}
	i<w로 해야 테스트케이스에 맞는 부분만 찾는다

2. ans가 테케마다 99999로 초기화 돼야 하는데 안 돼서
	그 전 테케의 ans와 비교하고 있었다

3. init() 까먹음

4. 맨 처음 깨는 블록을 block 변수에서 안 빼줬다
*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <queue>
#include<string.h>
using namespace std;
struct Pos{
	int y, x, num;
	Pos(int y, int x, int num) :y(y), x(x), num(num) {}
};
int n, w, h;
int total;
int block;
int ans=9999;
int arr[12];
int order[4];
int map[20][20];
int tmp[20][20];
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
queue<Pos> casc;
void dfs(int depth);
void run(int x);
void remove(int y, int x, int num);

void init(){
	memset(order, 0, sizeof(order));
	total = 0;
}
int main(int argc, char** argv)
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int test_case;
	int T;
	for (int i = 0; i < 12; i++)
		arr[i] = i;
	freopen("input.txt", "r", stdin);
	cin >> T;
	/*
	여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		init();
		cin >> n >> w >> h;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> map[i][j];
				if (map[i][j])
					total++;
			}
		}
		ans = total;
		dfs(0);
		cout << '#' << test_case << ' ' << ans << '\n';

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

void dfs(int depth) {
	if (depth == n) {
		block = total;

		memcpy(tmp, map, sizeof(tmp));
		for (int i = 0; i < n; i++)
			run(order[i]);
		if (block < ans)
			ans = block;
		return;
	}
	// 여기서 i<12로 했었다
	for (int i = 0; i < w; i++) {
		order[depth] = arr[i];
		dfs(depth + 1);
	}
}
void run(int x) {
	int y=0;
	while (tmp[y][x]==0 && y<h) {
		y++;
	}
	// 빈 열
	if (y >= h) {
		return;
	}

	int num = tmp[y][x];
	casc.push(Pos(y, x, tmp[y][x]));
	tmp[y][x] = 0;
	block--;
	while (!casc.empty()) {
		remove(casc.front().y, casc.front().x, casc.front().num);
		casc.pop();
	}


	// 중력
	queue<int> q;
	for (int j = 0; j < w; j++) {
		for (int i = h - 1; i >= 0; i--) {
			if (tmp[i][j]) {
				q.push(tmp[i][j]);
				tmp[i][j] = 0;
			}
		}
		int i = h - 1;
		while (!q.empty()) {
			tmp[i][j] = q.front();
			q.pop();
			i--;
		}
	}


}

void remove(int y, int x, int num) {
	for (int i = 0; i < 4; i++) {
		int ny = y;
		int nx = x;
		for (int cnt = 0; cnt < num-1; cnt++) {
			ny = ny + dy[i];
			nx = nx + dx[i];
			if (ny<0 || ny>h - 1 || nx<0 || nx>w - 1)
				continue;
			if (tmp[ny][nx]) {
				block--;
				if (tmp[ny][nx]!=1)
					casc.push(Pos(ny, nx, tmp[ny][nx]));
				tmp[ny][nx] = 0;
			}
		}
	}
}
