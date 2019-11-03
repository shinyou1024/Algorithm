#include <stdio.h>
#include <iostream>
#include <queue>
#include <string.h>
#include <algorithm>
using namespace std;
int map[1001][1001];
int dy[4]={1, -1, 0, 0};
int dx[4]={0, 0, -1, 1};
int n, m;
int dist[1001][1001][2]; // 해당 칸을 방문하기 전, 벽뚫기찬스가 남아있는지에 따라 다르게 저장 (0:아직안뚦 / 1: 이미뚫)

void bfs(int y, int x) {
    queue<pair<pair<int, int>,int> > q;
    q.push(make_pair(make_pair(y, x), 0));
    while(!q.empty()) {
        y = q.front().first.first;
        x = q.front().first.second;
        int z = q.front().second;
        //cout<<y<<","<<x<<","<<z<<endl;
        q.pop();

        for(int i=0; i<4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            // 범위에 벗어나지 않으면
            if(0<=ny && ny<n && 0<=nx && nx<m) {
                // 빈칸인경우, 방문한 적 없으면 방문
                if(map[ny][nx]==0 && dist[ny][nx][z]==0)  {
                    dist[ny][nx][z] = dist[y][x][z] + 1; // 지금까지의 이동거리 + 1
                    q.push(make_pair(make_pair(ny, nx),z));
                }
                // 벽인 경우
                if(map[ny][nx]==1) {
                    // 아직 벽을 부수지 않았고, 찬스를 쓴 후 방문하지 않았으면
                    if(z==0 && dist[ny][nx][1]==0) {
                        dist[ny][nx][1] = dist[y][x][0] + 1;
                        q.push(make_pair(make_pair(ny, nx), 1));
                    }
                }
            }
        }
    }
}

int main() {
    cin>>n>>m;
    memset(dist, 0, sizeof(dist));
    dist[0][0][0] = 1;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++)
            scanf("%1d", &map[i][j]);
    }

    bfs(0,0);

    // 벽을 부순 경우와 부수지 않은 경우 모두 종점에 도달했으면
    if(dist[n-1][m-1][0]!=0 && dist[n-1][m-1][1]!=0)
        cout << min(dist[n-1][m-1][0], dist[n-1][m-1][1]); // 그중작은것
    // 부수지 않은 경우에만 도달했으면
    else if(dist[n-1][m-1][0]!=0)
        cout << dist[n-1][m-1][0];
    // 부쉈을 때만 도달했으면
    else if(dist[n-1][m-1][1]!=0)
        cout << dist[n-1][m-1][1];
    // 벽을 부숴도, 부수지 않았어도 종점에 도달하지 못 한 경우
    else
        cout << -1;

    return 0;
}
