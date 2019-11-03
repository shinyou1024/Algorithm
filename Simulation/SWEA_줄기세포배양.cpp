
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


bool op1(Cell a, Cell b) {
	if (a.life - a.age > b.life - b.age)
		return true;
	else if (a.life - a.age == b.life - b.age)
		return a.life < b.life; // 같으면 생명력이 높은순
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
		vector<Cell> act;
		vector<Cell> inact;
		for (int i = 300; i < 300 + n; i++) {
			for (int j = 300; j < 300 + m; j++) {
				cin >> map[i][j];
				if (map[i][j]) {
					inact.push_back(Cell(i, j, map[i][j], 0));
				}
			}

		}
		queue<Cell> new_inact;
		queue<Cell> new_act;

		for(int t=0; t<=k; t++) {
      // 전 시간에 태어난 애들 inact에 추가
			while (!new_inact.empty()) {
				inact.push_back(new_inact.front());
				new_inact.pop();
			}
			sort(inact.begin(), inact.end(), op1);
      sort(act.begin(), act.end(), op2);
			// 활성화될애들
			for (int i = inact.size()-1; i >=0; i--) {
				if (inact[i].life == inact[i].age) {
					new_act.push(inact[i]);
					// 번식
					for (int d = 0; d < 4; d++) {
						int ny = inact[i].y + dy[d];
						int nx = inact[i].x + dx[d];
						if (map[ny][nx] == 0) {
							map[ny][nx] = inact[i].life;
							new_inact.push(Cell(ny, nx, inact[i].life, 0));
						}
					}
					inact.pop_back();
				}
        // 이 앞으로는 cut
				else
					break;
			}

			for (int i = act.size()-1; i >=0; i--) {
				if (act[i].age == act[i].life * 2) {
					act.pop_back();
				}
        // 이 앞으로는 cut
				else
					break;
			}

      // 새로 활성화된 애들 active에 넣기
			while (!new_act.empty()) {
				act.push_back(new_act.front());
				new_act.pop();
			}

      // 나이 먹기
			for (int i = 0; i < inact.size(); i++)
				inact[i].age++;
			for (int i = 0; i < act.size(); i++)
				act[i].age++;

		}
		cout << '#' << test_case << ' ' << inact.size() + act.size() << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
