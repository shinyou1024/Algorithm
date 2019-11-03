/*

오답노트
1. I, D 연산 : 맨 끝에서부터 다 옮겨줬어야...!
2. I 연산 : x부터 x+y-1까지는 소멸하는 게 아니라 얘도 뒤로 옮겨준 후에 입출력을 받아야 한다

정리
1. 배열에 관한 연산이 나올 땐 배열의 맨 끝자리가 어떨지도 고려하자
2. 입력으로 주어진 23356 17273 얘들은 한 자리 수 여러 개가 아니라 여러 자리 수 y개였다!
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;
int arr[100000];
int n;
int o;
int now; // 마지막 좌표
int x, y;
void init() {
	memset(arr, 0, sizeof(arr));
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen("input.txt", "r", stdin);
	for (int tc = 1; tc <= 10; tc++) {
		init();
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		now = n;
		cin >> o;
		for (int i = 0; i < o; i++) {
			char order;
			cin >> order;
			switch (order) {
			case 'I':
				cin >> x >> y;
				// 숫자 밀기
				for (int j = now; j >= x; j--) {
					arr[j + y] = arr[j];
				}

				// 새 숫자 넣기
				for (int j = x; j < x + y; j++) {
					cin >> arr[j];
				}
				now += y;
				break;
			case 'D':
				cin >> x >> y;
				for (int j = x; j < now - y; j++) {
					arr[j] = arr[j + y];
				}

				now -= y;
				break;
			case 'A':
				cin >> y;
				for (int j = now; j < now + y; j++) {
					cin >> arr[j];
				}
				now += y;
				break;
			}
		}
		cout << '#' << tc << ' ';
		for (int i = 0; i < 10; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
	}

	return 0;
}
