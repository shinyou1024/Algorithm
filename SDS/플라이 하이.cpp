#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
int T, n;
int map[501][501];
int dp[501][501];
int dy[4]={1,-1,0,0};
int dx[4]={0,0,1,-1};
int len = 0;

int dfs(int y,int x){

    if(dp[y][x])
        return dp[y][x];

    dp[y][x]=1;

    for(int i=0;i<4;i++){
        int ny=y+dy[i];
        int nx=x+dx[i];

        if(ny<0 ||ny>=n || nx<0 || nx>=n)
            continue;

        if(map[y][x]>=map[ny][nx])
            continue;

        dp[y][x]=max(dp[y][x],dfs(ny,nx)+1);

    }

    return dp[y][x];
}

void init() {
    memset(dp, 0, sizeof(dp));

}
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);

    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cin >> map[i][j];
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ans=max(ans,dfs(i,j));
            }
        }
        cout << '#' << tc << ' ' << ans << endl;
        init();
    }
    return 0;
}
