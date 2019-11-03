/*
* memset()의 시간복잡도는 상수임
오답노트
1. n=1일때 무한루프
  => 예외처리를 해 줘야 함!
*/
#include <iostream>
#include<stdio.h>
#include <string.h>

using namespace std;

typedef struct Block{
    char state;
    int time;

}BLOCK;

int r, c, n;
BLOCK map[210][210];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int visit[210][210];
void print_map() {
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++)
          cout<<map[i][j].state;
        cout<<"\n";
    }
}
void update(int y, int x) {
    if(map[y][x].state=='O') {
        map[y][x].time++;
    }
}

void bomb(int y, int x) {
    visit[y][x]=1;
    map[y][x].state='.';
    map[y][x].time=0;
    for(int i=0; i<4; i++) {
        int ny=y+dy[i];
        int nx=x+dx[i];

        if(0<=ny&&ny<r&&0<=nx&&nx<c) {
            if(!visit[ny][nx] && map[ny][nx].time!=3) {
                visit[ny][nx] = 1;
                map[ny][nx].state='.';
            }
        }
    }
}
int main() {
  ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> r >> c >> n;
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            char input;
            cin>>input;
            if(input=='.') {
                map[i][j].state='.';
            }
            else {
                map[i][j].state='O';
                map[i][j].time = 2;
            }
        }
    }

    int time = 1;
    while(1) {
        memset(visit, 0, sizeof(visit));
        time++;
        // .이면 심고 O면 time조정
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                if(map[i][j].state=='.') {
                    map[i][j].state='O';
                    map[i][j].time = 1;
                }
                else
                    map[i][j].time++;
            }
        }
        if(time==n)
            break;

        time++;
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                if(map[i][j].time==3)
                    bomb(i, j);
            }
        }
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                if(map[i][j].state=='O')
                    map[i][j].time++;
            }
        }
        if(time==n)
            break;

    }
    print_map();
    return 0;
}
