
#include <string>
#include <vector>
#include <string.h>
#include <queue>
#include <iostream>
using namespace std;
struct Pos{
    int y, x;
    Pos(int y, int x):y(y), x(x) {};
    Pos() {};
};
int flag;
queue<Pos> del;
char map[35][35];
// sy, sx 기준으로 확인
void check(int sy, int sx) {
    char block = map[sy][sx];
    if(map[sy][sx+1]==block && map[sy+1][sx]==block && map[sy+1][sx+1]==block) {
        flag = 1;
        del.push(Pos(sy, sx));
        del.push(Pos(sy, sx+1));
        del.push(Pos(sy+1, sx));
        del.push(Pos(sy+1, sx+1));
    }
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            map[i][j] = board[i][j];
        }
    }
    while(true) {
        // 깨트리기
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(map[i][j]!=' ') {
                    check(i, j);
                }
            }
        }

        // 삭제
        int visit[35][35];
        memset(visit, 0, sizeof(visit));
        while(!del.empty()) {
            int y = del.front().y; int x = del.front().x;
            del.pop();
            if(visit[y][x]) continue;
            else {
                map[y][x] = ' ';
                visit[y][x] = 1;
                answer++;
            }
        }

        // 중력
        for(int j=0; j<n; j++) {
            queue<char> remain;
            for(int i=m-1; i>=0; i--) {
                if(map[i][j]!=' ') {
                    remain.push(map[i][j]);
                    map[i][j] = ' ';
                }
            }
            int i=m-1;
            while(!remain.empty()) {
                map[i][j] = remain.front();
                remain.pop();
                i--;
            }
        }


        if(!flag) break;
        else flag = 0;
    }


    return answer;
}
