/*
오답노트
1. (0,0)부터 시작하는데 도형이 0,0기준이 아니라 마구잡이로 되어 있어서 모든 경우의 수를 커버하지 못 했다
예를 들어
0 0 0 1
0 0 0 1
0 0 0 1
0 0 0 1
이렇게 되어 있는 경우, 격자판의 첫 번째 열 부분은 커버할 수 없다

1 0 0 0
1 0 0 0
1 0 0 0
1 0 0 0
같은 도형을 이렇게 해야 격자판의 첫 열 부터 커버할 수 있다

2. 테르토미노를 확인할 때, 0부터 4까지의 인덱스를 줬어야 했는데
격자판 상의 인덱스인 y, x로 따져서 쓰레기 값을 참조했다. (i, j로 줘야 맞다!!!)


*/
#include <iostream>
#include <string.h>
using namespace std;
int w, h;
int tmp[4][4];
int ans;
int map[505][505];
int one[2][4][4] = { { { 1, 0, 0, 0 }, { 1, 0, 0, 0 }, { 1, 0, 0, 0 }, { 1, 0, 0, 0 } }, { { 1, 1, 1, 1 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 } } };
int two[4][4] = { { 1, 1, 0, 0 }, { 1, 1, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 } };
int three[4][4][4] = { {{ 1, 0, 0, 0 }, { 1, 0, 0, 0 }, { 1, 1, 0, 0 }, { 0, 0, 0, 0 } }, { { 1, 1, 1, 0 }, { 1, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 } }, { { 1, 1, 0, 0 }, { 0, 1, 0, 0 }, { 0, 1, 0, 0 }, { 0, 0, 0, 0 } }, { { 0, 0, 1, 0 }, { 1, 1, 1, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 } } };
int four[4][4][4] = { { { 0, 1, 0, 0 }, { 0, 1, 0, 0 }, { 1, 1, 0, 0 }, { 0, 0, 0, 0 } }, { { 1, 0, 0, 0 }, { 1, 1, 1, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 } }, { { 1, 1, 0, 0 }, { 1, 0, 0, 0 }, { 1, 0, 0, 0 }, { 0, 0, 0, 0 } }, { { 1, 1, 1, 0 }, { 0, 0, 1, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 } } };
int five[2][4][4] = { { { 1, 0, 0, 0 }, { 1, 1, 0, 0 }, { 0, 1, 0, 0 }, { 0, 0, 0, 0 } }, { { 0, 1, 1, 0 }, { 1, 1, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 } } };
int six[2][4][4] = { { { 0, 1, 0, 0 }, { 1, 1, 0, 0 }, { 1, 0, 0, 0 }, { 0, 0, 0, 0 } } , { { 1, 1, 0, 0 }, { 0, 1, 1, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 } } };
int seven[4][4][4] = { { { 1, 1, 1, 0 }, { 0, 1, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 } }, { { 0, 1, 0, 0 }, { 1, 1, 0, 0 }, { 0, 1, 0, 0 }, { 0, 0, 0, 0 } }, { { 0, 1, 0, 0 }, { 1, 1, 1, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 } }, { { 1, 0, 0, 0 }, { 1, 1, 0, 0 }, { 1, 0, 0, 0 } } };

/*
// 반시계 회전
void rotate(int arr[4][4]) {
	int tmp2[4][4];
	memcpy(tmp2, arr, sizeof(tmp2));
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			tmp2[i][j] = arr[j][i];
		}
	}
	cout << "====" << endl;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << tmp2[i][j] << ' ';
		}
		cout << endl;
	}
	memcpy(tmp, tmp2, sizeof(tmp));
}
void run() {

	//시작점에대한이중포문 : 시작점 (i, j)
	for (int sy = 0; sy < h; sy++) {
		for (int sx = 0; sx < w; sx++) {
			int sum = 0;
			for (int i = 0; i < 4; i++) {
				int y = sy + i;
				if (y<0 || y>h - 1) continue;
				for (int j = 0; j < 4; j++) {
					int x = sx + j;
					if (x<0 || x>w - 1) continue;
					if (tmp[y][x] == 1) {
						sum += map[y][x];
					}

				}
			}
			ans = sum > ans ? sum : ans;
		}
	}
}




void start(int arr[4][4], int idx) {
	memcpy(tmp, arr, sizeof(tmp));
	run();
	if (idx == 1 || idx==5 || idx==6) {
		rotate(tmp);
		run();
	}

	else if (idx == 3 || idx==4 || idx== 7) {
		for (int i = 0; i < 3; i++) {
			rotate(tmp);
			run();
		}
	}
}
*/

void run() {

	//시작점에대한이중포문 : 시작점 (i, j)
	for (int sy = 0; sy < h; sy++) {
		for (int sx = 0; sx < w; sx++) {
			int sum = 0;
			for (int i = 0; i < 4; i++) {
				int y = sy + i;
				if (y<0 || y>h - 1) continue;
				for (int j = 0; j < 4; j++) {
					int x = sx + j;
					if (x<0 || x>w - 1) continue;
					if (tmp[i][j] == 1) {
						sum += map[y][x];
					}

				}
			}
			ans = sum > ans ? sum : ans;
		}
	}
}




void start1(int arr[2][4][4]) {
	for (int i = 0; i < 2; i++) {
		memcpy(tmp, arr[i], sizeof(tmp));

		run();
	}

}

void start2(int arr[4][4][4]) {
	for (int i = 0; i < 4; i++) {
		memcpy(tmp, arr[i], sizeof(tmp));
		run();

	}
}
void start3(int arr[4][4]) {
	memcpy(tmp, arr, sizeof(tmp));
	run();
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> h >> w;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> map[i][j];
		}
	}
	start1(one);
	start3(two);
	start2(three);
	start2(four);
	start1(five);
	start1(six);
	start2(seven);
	cout << ans;
	return 0;
}
