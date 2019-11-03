#include <iostream>
#include<cstring>
#include<cstdlib>
using namespace std;

int tc;
int n, result;
int map[21][21];
bool r[21][21];
bool d[101];
int sx, sy;//출발위치
int dx[] = { 1,1,-1,-1 };// 방항 중요함 -> 어떤식으로 선택해야할지
int dy[] = { 1,-1,-1,1 };
void dfs(int x, int y, int dir, int cnt) {
   if (x == sx && y == sy && cnt > 1) {//종결
      result = result > cnt ? result : cnt;
      return;
   }
   for (int i = 0; i < 2; i++) {//방향은 딱 두개 -> 배열 초과하게 냅두기
      int nx = x + dx[dir + i];
      int ny = y + dy[dir + i];
      if (nx >= 0 && ny >= 0 && nx < n && ny < n && r[nx][ny] == false && d[map[nx][ny]] == false) {
         r[nx][ny] = true;
         d[map[nx][ny]] = true;
         cout << endl;
         for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
               if (r[i][j] == true) {
                  cout << 1 << " ";
               }
               else cout << 0 << " ";

            }
            cout << endl;
         }
         dfs(nx, ny, dir + i, cnt + 1);
         r[nx][ny] = false;
         d[map[nx][ny]] = false;
      }
      else if (nx == sx && ny == sy) {
         dfs(nx, ny, dir + i, cnt + 1);
      }
   }
}
int main() {

   cin >> tc;
   for (int t = 1; t <= tc; t++) {
      //start
      result = -1;
      cin >> n;
      memset(d, false, sizeof(d));//d
      for (int i = 0; i < n; i++) {
         for (int j = 0; j < n; j++) {
            cin >> map[i][j];
            r[i][j] = false;//map checking initialized
         }
      }
      for (int i = 0; i < n - 1; i++) {
         for (int j = 1; j < n - 1; j++) {
            sx = i;
            sy = j;
            d[map[i][j]] = true;
            dfs(i, j, 0, 0);
            d[map[i][j]] = false;
         }
      }
      cout << '#' << t << ' ' << result << endl;
   }
}
