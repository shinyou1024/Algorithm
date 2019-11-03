#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
// 죽은 나무에서 추가될 양분 기록할 데이터
struct Data{
    int y, x, plus;
    Data(int y, int x, int plus):y(y), x(x), plus(plus) {};
    Data() {};
};

int  n, m, k;
vector<int> namu[15][15]; // (r, c)에 있는 나무들
int yum[15][15]; // 땅의 양분
int robot[15][15]; // 겨울에 추가되는 양분
queue<Data> yum_plus; // 죽은 나무에서 여름에 추가될 양분
int ans; // 나무 수 카운팅
int dy[]={-1, -1, -1, 0, 0, 1, 1, 1};
int dx[]={-1, 0, 1, -1, 1, -1, 0, 1};

void ss() {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            int idx = namu[i][j].size();
            int dead = 0;
            for(int p=0; p<idx; p++) {
                if(yum[i][j]>=namu[i][j][p]) {
                    // 이거 순서 반대로 해서 에러... 양분먼저 빼고 나이올려줘야 함!
                    yum[i][j] -= namu[i][j][p];
                    namu[i][j][p]++;
                }
                else {
                    dead++;
                    yum_plus.push(Data(i, j, namu[i][j][p]/2));
                    ans--;
                }
            }
            while(dead--) {
                namu[i][j].pop_back();
            }
        }
    }
    // 여름
    while(!yum_plus.empty()) {
        int y, x, add;
        y = yum_plus.front().y;
        x = yum_plus.front().x;
        add = yum_plus.front().plus;
        yum[y][x] += add;
        yum_plus.pop();
    }
}

void fw() {
    queue<Data> baby;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            for(int p=0; p<namu[i][j].size(); p++) {
                if(namu[i][j][p]%5==0) {
                    for(int d=0; d<8; d++) {
                        int ny = i + dy[d];
                        int nx = j + dx[d];
                        if(ny<0 || ny>n-1 || nx<0 || nx>n-1) continue;
                        baby.push(Data(ny, nx, 1));
                        ans++;
                    }
                }
            }
        }
    }
    while(!baby.empty()) {
        int y = baby.front().y;
        int x = baby.front().x;
        namu[y][x].push_back(1);
        baby.pop();
    }

    //겨울
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            yum[i][j] += robot[i][j];
        }
    }
}
int main() {
    cin >> n >> m >> k;
    ans = m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            int input;
            cin >> input;
            robot[i][j] = input;
            yum[i][j] = 5;
        }
    }

    for(int i=0; i<m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        namu[x-1][y-1].push_back(z);
    }

    while(k--) {
        ss();
        fw();
        // 각 칸마다 나무들을 나이순으로 정렬
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                sort(namu[i][j].begin(), namu[i][j].end());
            }
        }

    }
    cout<<ans;
    return 0;
}
