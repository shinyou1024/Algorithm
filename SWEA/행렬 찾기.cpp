#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct Matrix{
	int s;
	int r;
	int c;
	Matrix(int s, int r, int c) : s(s), r(r), c(c) {};
};
int T;
int n;
int map[101][101];
int visit[101][101];
vector<Matrix> v;
bool comp(Matrix m1, Matrix m2) {
	if (m1.s == m2.s){
		return m1.r < m2.r;
	}
	else{
		return m1.s < m2.s;
	}

}
void init() {
	memset(visit, 0, sizeof(visit));
	memset(map, 0, sizeof(map));
	v.clear();
}
void run(int y, int x) {
	int ny = y;
	int nx = x;
	int ansy = 0, ansx = 0;
	while (map[ny][nx] != 0) {
		ansx++;
		nx++;
	}
	ny = y;
	nx = x;
	while (map[ny][nx] != 0) {
		ansy++;
		ny++;
	}

	for (int i = y; i < y + ansy; i++) {
		for (int j = x; j < x + ansx; j++)
			visit[i][j] = 1;
	}
	v.push_back(Matrix(ansy*ansx, ansy, ansx));
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen("input.txt", "r", stdin);
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		init();
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] && !visit[i][j]) {
					run(i, j);
				}
				visit[i][j] = 1;
			}
		}


		sort(v.begin(), v.end(), comp);
		cout << '#' << tc << ' ' << v.size() << ' ';
		for (int i = 0; i < v.size(); i++) {
			cout << v[i].r << ' ' << v[i].c << ' ';
		}
		cout << '\n';
	}
	return 0;
}
