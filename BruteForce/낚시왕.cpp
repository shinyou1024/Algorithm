#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
int dy[]={0, -1, 1, 0, 0};
int dx[]={0, 0, 0, 1, -1};
int r, c, m;
int tmp[101][101];
int map[101][101];
struct Shark{
    int dead=0;
    int idx;
    int y, x;
    int size;
    int dir;
    int v;
};

Shark shark[10000+2];

void move(int idx) {
    int ny=shark[idx].y;
    int nx=shark[idx].x;
    int v = shark[idx].v;
    int size = shark[idx].size;
    for(int k=0; k<v; k++) {
        int dir = shark[idx].dir;
        ny = ny+dy[dir];
        nx = nx+dx[dir];
        cout<<ny<<','<<nx<<endl;
        if(ny<0) {
            ny = 0;
            shark[idx].dir = 2;
        }
        if(ny>r-1) {
            ny = r-1;
            shark[idx].dir = 1;
        }
        if(nx<0) {
            nx = 0;
            shark[idx].dir = 3;
        }
        if(nx<c-1) {
            nx = c-1;
            shark[idx].dir = 4;
        }
    }
    shark[idx].y = ny;
    shark[idx].x = nx;

    // 두마리 이상
    if(!tmp[ny][nx]) {
        // 자기가 크면 바꾸기
        if(tmp[ny][nx]<size) {
            int prev = tmp[ny][nx];
            shark[prev].dead = 1;
            tmp[ny][nx] = idx;
        }
    }
}


void print() {
    cout<<"======================="<<endl;
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++)
            cout<<map[i][j]<<' ';
        cout <<endl;
    }
}
int ans;
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    //freopen("input.rtf", "r", stdin);
    cin >> r >> c >> m;
    for(int i=1; i<=m; i++) {
        int y, x;
        cin >> y >> x >>shark[i].v >> shark[i].dir >> shark[i].size;
        shark[i].y = y-1;
        shark[i].x = x-1;
        shark[i].idx = i;
    }
    memset(map, 0, sizeof(map));
    for(int i=1; i<=m; i++) {
        int y = shark[i].y;;
        int x = shark[i].x;;
        map[y][x] = i;
    }
    for(int i=0; i<c; i++) {
        memset(tmp, 0, sizeof(tmp));
        // 상어잡기
        for(int j=0; j<r; j++) {
            if(map[j][i]!=0) {
                int idx = map[j][i];
                ans += shark[idx].size;
                shark[idx].dead = 1;
                map[j][i] = 0;
                break;
            }
        }
        // 상어 이동
        for(int k=1; k<=m; k++) {
            if(shark[k].dead==1)
                continue;
            move(k);
        }
        // 복사
        memcpy(map, tmp, sizeof(map));

    }
    cout <<ans;
    return 0;
}
