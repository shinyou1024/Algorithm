/*
 풀이
 1. map[][]에 뱀의 몸이 있는 칸을 1로 만들어주기
 2. 큐에 몸의 좌표 넣어주기
 => front가 꼬리, back이 머리(먼저들어간게꼬리가됨)
 => 사과만나면 pop()해서 꼬리빼주고, 새로운 꼬리좌표를 그 다음front()로지정
 */

#include <iostream>
#include <queue>
#include <string.h>

using namespace std;
int n, k, o;
// 동:0, 서:1, 남:2, 북:3 순
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};
int map[200][200];
pair<int, char> order[200];
int t=0;
int len=1;
int dir=0;
int hy=1, hx=1, ty=1, tx=1; // 머리와 꼬리의 좌표
queue<pair<int, int> > snake;
// 방향 변환 하지 않을 때의 이동
// (y,x):머리의위치
bool run(int d) {
    // 머리가 위치할 새로운 칸의 좌표
    hy=hy+dy[d];
    hx=hx+dx[d];
    //cout<<hy<<","<<hx<<endl;
    //cout<<"머리"<<hy<<","<<hx<<endl;
    // 몸이거나 벽이면
    // 오타!!!!(hy>n을 두번씀..)
    if(map[hy][hx]==1||hy<1||hy>n||hx<1||hx>n) {

        return false;
    }
    // 사과면
    else if(map[hy][hx]==2) {
        snake.push(make_pair(hy, hx)); // 머리좌표넣기
        map[hy][hx]=1;
        len++;
    }
    // 사과가 아니면
    else {
        snake.push(make_pair(hy, hx));
        snake.pop(); // 꼬리 빼기
        map[hy][hx]=1;
        map[ty][tx]=0;
        // 새로운 꼬리의 좌표

        ty=snake.front().first;
        tx=snake.front().second;
        //cout<<"꼬리:"<<ty<<","<<tx<<endl;

    }
    return true;
}

void dirChange(char c) {
    //cout<<c<<endl;
    if(c=='L') {
        if(dir==0)
            dir=3;
        else if(dir==1)
            dir=2;
        else if(dir==2)
            dir=0;
        else if(dir==3)
            dir=1;
    }
    if(c=='D') {
        if(dir==0)
            dir=2;
        else if(dir==1)
            dir=3;
        else if(dir==2)
            dir=1;
        else if(dir==3)
            dir=0;
    }
    //cout<<"새방향"<<dir<<endl;
}
int main() {

    cin >> n;
    memset(map, 0, sizeof(map)); // 보드 초기화
    map[1][1]=1; // 뱀의 처음 위치
    snake.push(make_pair(1,1)); // 뱀몸통좌표
    cin>>k;
    if(k!=0) {
        for(int i=0; i<k; i++) {
            int r, c;
            cin >> r >> c;
            map[r][c]=2;
        }
    }
    cin>>o;
    if(o!=0) {
        for(int i=0; i<o; i++) {
            int x;
            char c;
            cin >> x >> c;
            order[i]=make_pair(x, c);
        }
    }

    int time = 0;
    int idx=0; // order[]의 인덱스

    //cout<<"\n";

    // 게임실행
    while(true) {
        time++;

        //cout<<time<<"초"<<endl;
        bool isLive;
        isLive = run(dir);
        if(isLive==false) {
            //cout<<time<<endl;
            break;
        }
        if(time==order[idx].first) {
            //cout<<"방향변환"<<endl;
            dirChange(order[idx].second);
            idx++;
        }

    }


    cout<<time;
    return 0;
}
