#include <iostream>
#include <queue>
using namespace std;

struct Pos{
   int y;
   int x;
   Pos(int a, int b) {
       y = a;
       x = b;
   }
   Pos();
};
struct Block{
   Pos p;
   int len;
   Block(int a, int b, int c) {
       p.y = a;
       p.x = b;
       len = c;
   }
   Block();
};

int n;
int map[110][110];
int visit[110][110];
int dy[4]={-1, 0, 1, 0};
int dx[4]={0, 1, 0, -1};
int total;

// 각 섬 구분하기
void island(int y, int x) {
   queue<Pos> q;
   q.push(Pos(y, x));
   visit[y][x] = 1;

   while(!q.empty()) {
       y = q.front().y;
       x = q.front().x;
       for(int i=0; i<4; i++) {
           int ny = y + dy[i];
           int nx = x + dx[i];
           if(ny<0 || ny>n-1 || nx<0 || nx>n-1)
               continue;
           if(map[ny][nx]==1) {
               map[ny][nx]=total+1; // 몇번째대륙인지표시
               visit[ny][nx]=1;
               q.push(Pos(y,x));
           }
       }

   }

}
int main() {
   cin >> n;
   for(int i=0; i<n; i++) {
       for(int j=0; j<n; j++) {
           cin >> map[i][j];
       }
   }

   for(int i=0; i<n; i++) {
       for(int j=0; j<n; j++) {
           if(!visit[i][j]&&map[i][j]==1) {
               island(i, j);
           }
       }
   }
   cout<<total;
   return 0;
}
