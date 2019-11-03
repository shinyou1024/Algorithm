/*
오답노트
1. 원래 check()내에서 빙산의 줄어든 높이를 바로바로 업데이트 했는데
  이렇게 하면 그 다음 칸도 영향을 받기 때문에 검사를 다 한 후에 한 번에 업데이트 해줘야 함
2. 행과 열의 범위가 다름 => bfs 범위체크시 nx>n-1로 해서 틀림

스터디
1. pair보다 구조체를 쓰자!
*/
#include<iostream>
#include<queue>
#include<vector>
#include<string.h>
using namespace std;
int n, m;
int total;
int map[310][310];
vector<pair<pair<int, int>, int> > v; // 구조체 쓰는 게 좋다
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int visit[310][310];


void check(int y, int x) {
    if(map[y][x]==0)
        return;
    int cnt = 0;
    for(int i=0; i<4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny<0 || ny >n-1 || nx <0 || nx > m-1)
            continue;
        if(map[ny][nx]==0) {
            //cout<<y<<","<<x<< "|"<<ny<<","<<nx<<endl;
            cnt++;
        }
    }

    if(map[y][x]>=cnt) {
        v.push_back(make_pair(make_pair(y, x), map[y][x]-cnt));
    }
    else
        v.push_back(make_pair(make_pair(y, x), 0));
}

void update() {
    for(int i=0; i<v.size(); i++) {
        int y = v[i].first.first;
        int x = v[i].first.second;
        int u = v[i].second;

        map[y][x] = u;
        if(u==0)
            total--;
    }
    v.clear();
}
// 빙산이 두 조각 이상인지 확인
bool isSplited(int y, int x) {
    visit[y][x]=1;
    queue<pair<int, int> > q;
    q.push(make_pair(y, x));
    int cnt=1;
    while(!q.empty()) {
        y = q.front().first;
        x = q.front().second;
        q.pop();

        for(int i=0; i<4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny<0 || ny >n-1 || nx <0 || nx > m-1)
                continue;
            if(visit[ny][nx])
                continue;
            if(map[ny][nx]!=0) {
                q.push(make_pair(ny, nx));
                visit[ny][nx] = 1;
                cnt++;
            }
        }
    }
    if(cnt!=total)
        return true;
    else
        return false;
}


int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 || i == n - 1 || j == 0 || j == m - 1) map[i][j] = 0;
            int input;
            cin >> input;
            if(input!=0)
                total++;
            map[i][j]=input;
        }
    }

    int con = 0;
    int done = 0;
    int year = 0;

    while(total!=0) {
        year++;
        memset(visit, 0, sizeof(visit));
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++)
                check(i, j);
        }
        update();
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++)
                if(map[i][j]!=0) {
                    con=1;
                    if(isSplited(i, j)) {
                        done = 1;
                        cout<<year;
                    }
                    break;
                }
            if(con==1)
                break;
        }
        if(!done)
            con = 0;

        else
            break;

    }
    if(!done)
        cout<<0;
    return 0;
}
