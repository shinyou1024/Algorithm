#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
struct Pos{
    int y;
    int x;
    Pos(int y, int x) : y(y), x(x) {}
};

int R, C, T;
int map[51][51];
int tmp[51][51];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
vector<Pos> cleaner;
void bfs(int y, int x);
void update();
void clean_up(int y, int x);
void clean_down(int y, int x);
int count();
void init() {
    memset(tmp, 0, sizeof(tmp));
}
void print() {
    cout<<"======================="<<endl;
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++)
            cout << map[i][j] <<' ';
          cout <<endl;
    }

}
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>R>>C>>T;
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            cin >> map[i][j];
            if(map[i][j]==-1) {
                cleaner.push_back(Pos(i, j));
            }
        }
    }
    for(int t=0; t<T; t++) {
        init();
        for(int i=0; i<R; i++) {
            for(int j=0; j<C; j++) {
                if(map[i][j]<1)
                    continue;
                bfs(i, j);
            }
        }
        update();
        clean_up(cleaner[0].y, cleaner[0].x);
        clean_down(cleaner[1].y, cleaner[1].x);
    }
    print();


    cout<<count();
    return 0;
}

void bfs(int y, int x){
    int cnt = 0;
    int num = map[y][x];
    for(int i=0; i<4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny<0 || ny>R-1 || nx<0 || nx>C-1)
            continue;
        if(map[ny][nx]==-1)
            continue;
        tmp[ny][nx] += num/5;
        cnt++;
    }
    map[y][x] = num - (num/5)*cnt;
}
void update() {
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            map[i][j] += tmp[i][j];
        }
    }
}

void clean_up(int y, int x) {
    queue<int> q;
    q.push(0);
    int ny=y;
    int nx=x+1;
    q.push(map[ny][nx]);
    int d=0;
    int dy2[] = {0, -1, 0, 1};
    int dx2[] = {1, 0, -1, 0};

    while(!(ny==y && nx==x)) {
        ny = ny + dy2[d];
        nx = nx + dx2[d];

        q.push(map[ny][nx]);
        if((ny==y&&nx==C-1) || (ny==0&&nx==C-1) || (ny==0&&nx==0) || (ny==y&&nx==0)){
            d = (d+1)%4;
        }
    }
// 마지막꺼 버리기

    // map 업데이트
    ny = y;
    nx = x;
    d = 0;
    while(q.size()>1) {
        ny = ny + dy2[d];
        nx = nx + dx2[d];
        map[ny][nx] = q.front();
        cout<<"=================="<<endl;
        cout<<q.front()<<' ';
        q.pop();
        if((ny==y&&nx==C-1) || (ny==0&&nx==C-1) || (ny==0&&nx==0) || (ny==y&&nx==0)) {
            d = (d+1)%4;
        }
    }





}

void clean_down(int y, int x) {
    queue<int> q;
    q.push(0);
    int ny = y;
    int nx = x+1;
    q.push(map[ny][nx]);
    int d=0;
    int dy2[] = {0, 1, 0, -1};
    int dx2[] = {1, 0, -1, 0};

    while(!(ny==y && nx==x)) {

        ny = ny + dy2[d];
        nx = nx + dx2[d];

        q.push(map[ny][nx]);
        if((ny==y&&nx==C-1) || (ny==R-1&&nx==C-1) || (ny==R-1&&nx==0) || (ny==y&&nx==0)) {
            d = (d+1)%4;
        }
    }

    // map 업데이트
    ny = y;
    nx = x;
    d = 0;
    while(q.size()>1) {
        ny = ny + dy2[d];
        nx = nx + dx2[d];
        map[ny][nx] = q.front();
        q.pop();
        if((ny==y&&nx==C-1) || (ny==R-1&&nx==C-1) || (ny==R-1&&nx==0) || (ny==y&&nx==0))  {
            d = (d+1)%4;
        }


    }
}



int count() {
    int total = 0;
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            if(map[i][j]==-1)
                continue;
            total += map[i][j];
        }
    }
    return total;
}
