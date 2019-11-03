/*
 오답노트
 1.
 2. 144줄 : 여기서 searched를 초기화해주면 절대 for문을 벗어날 수 없음..!

 질문
 1. map을 h보다 뒤에 선언했더니 h값이 자꾸 이상해짐..!?
 */

#include <stdio.h>
#include <queue>
#include <string.h>
#include <stack>
using namespace std;
char color[20]={'R', 'G', 'B', 'P', 'Y'};
int all = 0;
char map[20][20];
int h[8];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int chk;
bool visit[20][20]; //이거안됨
bool ret;
int con = 0;//연쇄의 횟수
int puyo = 0; //보드위의 뿌요개수

queue<pair<int, int> > toDelete; //터질 뿌요의 좌표
stack<pair<int, int> > deleted;

void fall() {

    while (!deleted.empty()) {
        int i = deleted.top().first;
        int j = deleted.top().second;


        if (h[j] == 0) {
            map[i][j] = '.';
        }
        else {

            int y = i;
            for (int k = 0; k < h[j]; k++) {
                if(1<=y&&y<=12) {
                    map[y][j] = map[y - 1][j];
                    map[y - 1][j] = '.';
                    y--;
                }
            }
        }
        deleted.pop();
    }
}

void del() {
    while (!toDelete.empty()) {
        int y = toDelete.front().first;
        int x = toDelete.front().second;
        deleted.push(make_pair(y, x));
        map[y][x] = 'd';
        h[x]--;
        puyo--;
        toDelete.pop();
    }
}

void bfs(int y, int x) {
    //cout<<y<<","<<x<<"확인"<<endl;
    char C = map[y][x];
    visit[y][x] = true;
    queue<pair<int, int> > q;
    q.push(make_pair(y, x));

    bool check[20][20] = { false }; // 한 bfs안에서의 방문기록
    check[y][x] = true;

    queue<pair<int, int> > same;
    same.push(make_pair(y, x));

    int cnt = 1;



    while (!q.empty()) {
        y = q.front().first;
        x = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {

            int ny = y + dy[i];
            int nx = x + dx[i];
            // 범위 벗어날경우
            if (ny < 1 || ny>12 || nx < 1 || nx>12) {
                continue;
            }
            if (check[ny][nx] == false && map[ny][nx] == C) {
                //cout<<ny<<","<<nx<<"일치"<<endl;
                cnt++;
                q.push(make_pair(ny, nx));
                check[ny][nx] = true;
                same.push(make_pair(ny, nx));
            }
        }

    }
    if (cnt >= 4) {
        chk++;
        for (int i = 0; i < cnt; i++) {
            int a = same.front().first;
            int b = same.front().second;
            toDelete.push(make_pair(a, b));
            visit[a][b] = true;
            same.pop();
        }
    }
}



int main() {
    memset(h, 0, sizeof(h));
    for (int i = 1; i <= 12; i++) {
        for (int j = 1; j <= 6; j++) {
            cin >> map[i][j];
            if (map[i][j] != '.') {
                puyo++;
                h[j]++;
            }
        }
    }

    // 모든 뿌요를 검사했는데 터트릴 게 없으면 끝
    // 72-dot : 남은 뿌요

    while (true) {
        for (int i = 12; i >= 1; i--) {
            for (int j = 1; j <= 6; j++) {
                if (map[i][j]=='.') {
                    continue;
                }
                if (visit[i][j] == false) {
                    bfs(i, j);
                }
            }
        }
        //cout<<chk<<endl;
        if(chk>0) {
            chk=0;
            del();
            fall();
            con++;
        }

        else
            break;

        memset(visit, false, sizeof(visit));

        /*
         for (int i = 1; i <= 12; i++) {
         for (int j = 1; j <= 6; j++) {
         cout<< map[i][j];
         }
         cout << "\n";
         }
         cout << "==========================================\n";
         cout<<"chk"<<chk<<endl;
         */
    }
    cout << con;
    return 0;
}
