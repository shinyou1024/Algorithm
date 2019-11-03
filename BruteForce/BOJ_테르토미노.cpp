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
