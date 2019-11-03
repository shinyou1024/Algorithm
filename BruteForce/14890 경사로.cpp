/*
오답노트
1. 여기 1:
	경사로의 길이 L이 1일 경우, cnt가 0이어서 불가능한 경우로 카운팅된다
	=> if ((cnt >= l || l == 1) && map[i][c] - h == 1)처럼 cnt가 충분한 경우와 L이 1인 경우를 묶어서 검사해주면 해결
2. 여기 2:
	단순 오타
	경사로의 표시는 map이 아니라 check에 해주어야 하는데
	map에다가 표시하는 바람에 '여기3'에서 계속 오류가 났다. (높낮이를 바꿔버렸으니까)

풀이방식
	1- 각 행과 열의 칸들을 그 전의 칸의 높이 h와 비교한다
	2- 높이가 연속적인 칸들은 cnt로 그 길이를 기록
	3- 현재 칸이 그 전 칸과 연속한 경우, 오르막인 경우, 내리막인 경우로 나눈다
	4- 연속한 경우면 cnt만 늘려준다
	5- 오르막인 경우,
		1) 경사로를 놓을 길이가 충분한지, 높이차가 1인지 확인(cnt와 l을 비교해주는 게 핵심!)
		2) 그 전에 놓은 경사로와 겹치지 않는지 검사한다
		3) cnt초기화, h값 변경
	6- 내리막인 경우,
		1) 높이차가 1인지 확인
		2) 연속된 칸들의 높이를 확인 => 경사로를 놓을 공간이 있는지
		3) 겹치는지는 확인할 필요 x
		4) h값 변경

	5와 6을 정리하면
	경사로를 놓을 길이가 충분한지, 높이차가 1인지 확인하는 게 핵심이다
	오르막 : cnt변수를 이용해 경사로 놓을 공간 확인. 겹치는 것 확인 필요
	내리막 : 앞의 칸들의 높이를 검사해 경사로 놓을 공간 확인.
	=> 오르막만 겹치는 것을 확인하면 된다 (이전 칸들에게 영향을 받으므로)


*/
#include <iostream>
#include <string.h>
using namespace std;
int map[110][110];
int check[110][110]; //경사로가 놓였는지 표시
int n, l;
int ans;
bool run_r(int r);
bool run_c(int c);
int main() {
	cin >> n >> l;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> map[i][j];
	}

	// 행
	for (int i = 0; i < n; i++) {
		memset(check, 0, sizeof(check));
		if (run_r(i)) {
			ans++;
		}
	}
	// 열
	for (int i = 0; i < n; i++) {
		memset(check, 0, sizeof(check));
		if (run_c(i)) {
			ans++;
		}
	}
	cout << ans;
	return 0;
}

bool run_r(int r) {
	int h = map[r][0]; // 이전에 연속해 온 높이
	int cnt = 1; // 연속한 것들
	for (int i = 1; i < n; i++) {
		// 같은 높이인 경우
		if (map[r][i] == h)
			cnt++;
		// 오르막일 경우
		else if (map[r][i] > h) {
			// 가능
			if ((cnt >= l||l==1) && map[r][i] - h == 1) {
				// 겹치는지 확인
				for (int c = 1; c <= l; c++) {
					if (check[r][i - c] == 1) {
						return false;
					}
					check[r][i - c] = 1;
				}
			}
			// 불가능
			else {
				//여기 1
				return false;
			}
			cnt = 0;
			h = map[r][i];
		}
		// 내리막일 경우
		else {
			// 높이차이 확인
			if (h - map[r][i] == 1) {
				// 경사로 놓을 길이가 충분한지
				for (int k = 0; k < l; k++) {
					if (map[r][i + k] != map[r][i]) {
						// 여기 3
						return false;
					}
					check[r][i + k] = 1;
				}
			}
			else {
				return false;
			}
			h = map[r][i];
		}

	}
	return true;
}

bool run_c(int c) {
	int h = map[0][c]; // 이전에 연속해 온 높이
	int cnt = 1; // 연속한 것들
	for (int i = 1; i < n; i++) {
		// 같은 높이인 경우
		if (map[i][c] == h)
			cnt++;
		// 오르막일 경우
		else if (map[i][c] > h) {
			// 가능
			if ((cnt >= l || l == 1) && map[i][c] - h == 1) {
				// 겹치는지 확인
				for (int k = 1; k <= l; k++) {
					if (check[i - k][c] == 1) {
						return false;
					}
					check[i-k][c] = 1;
				}
			}
			// 불가능
			else {
				return false;
			}
			cnt == 0;
			h = map[i][c];
		}
		// 내리막일 경우
		else {
			// 높이차이 확인
			if (h - map[i][c] == 1) {
				// 경사로 놓을 길이가 충분한지
				for (int k = 0; k < l; k++) {
					if (map[i + k][c] != map[i][c]) {
						return false;
					}
					check[i+k][c] = 1;
				}
			}
			else {
				return false;
			}
			h = map[i][c];
		}

	}
	return true;
}
