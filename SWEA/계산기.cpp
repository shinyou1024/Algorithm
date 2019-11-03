/*
오답노트
1. init()을 이상한 데서 해줘서 초기화가 안 됐음
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;
int T, n;
int arr[12];
int ans;

void init() {
	ans = 0;
}

void run(int now, int target, int cnt) {
	// 한 자리수로 나눠서 되는 경우
	for (int i = 0; i < 10; i++) {
		if (arr[i] == 0)
			continue;
		if (target%arr[i] == 0) {
			run(i, target / arr[i], )
		}
	}

}

int make_num(int target, int cnt) {
	// 그냥 누를 수 있는 경우

	// 곱셈으로 만드는 경우
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "r", stdin);

	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> n;
		for (int i = 0; i < 9; i++)
			cin >> arr[i];




	}



	return 0;
}
