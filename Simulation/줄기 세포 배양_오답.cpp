/*
1. 번식할 때 상하좌우 탐색시 dy, dx를 안 더해줌;
*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
using namespace std;
struct Cell{
	int y;
	int x;
	int life;
	int age;
	Cell(int y, int x, int life, int age) : y(y), x(x), life(life), age(age) {}
};
int n, m, k;
int map[700][700];
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
vector<Cell> act;
vector<Cell> inact;
queue<Cell> birth;
queue<Cell> newly_act;
bool op1(Cell a, Cell b) {
	if (a.life - a.age > b.life - b.age)
		return true;
	else if (a.life - a.age == b.life - b.age)
		return a.life<b.life;
	else
		return false;
}

bool op2(Cell a, Cell b) {
	return (a.life * 2 - a.age > b.life * 2 - b.age);
}
void init() {
	memset(map, 0, sizeof(map));
}


int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		init();
		cin >> n >> m >> k;

		for (int i = 300; i < 300 + n; i++) {
			for (int j = 300; j < 300 + m; j++) {
				cin >> map[i][j];
				if (map[i][j]) {
					inact.push_back(Cell(i, j, map[i][j], 0));
				}
			}

		}
		sort(inact.begin(), inact.end(), op1);



		int time = 0;
		while (k--) {

			// 시간된 애 활성화 + 번식
			for (int i = inact.size()-1; i >=0; i--) {
				while (!birth.empty()) {
					inact.push_back(birth.front());
					birth.pop();
				}

				while (!newly_act.empty()) {
					act.push_back(newly_act.front());
					newly_act.pop();
				}
				sort(inact.begin(), inact.end(), op1);
				sort(act.begin(), act.end(), op2);

				if (inact[i].age == inact[i].life) {
					for (int d = 0; d < 4; d++) {
						int ny = inact[i].y+dy[d];
						int nx = inact[i].x+dx[d];
						if (map[ny][nx] == 0) {

							map[ny][nx] = inact[i].life;
							birth.push(Cell(ny, nx, inact[i].life, 0));
						}
					}
					newly_act.push(Cell(inact[i].y, inact[i].x, inact[i].life, inact[i].age++));
					inact.pop_back();
				}

			}
			// 죽이기
			for (int i = act.size() - 1; i >= 0; i--) {
				if (act[i].age == act[i].life * 2) {
					map[act[i].y][act[i].x] = 11;
					act.pop_back();
				}
			}


			for (int i = 0; i < inact.size(); i++)
				inact[i].age++;
			for (int i = 0; i < act.size(); i++)
				act[i].age++;


			//print();
			time++;
		}
		cout << '#' << test_case << ' ' << inact.size() + act.size() << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
