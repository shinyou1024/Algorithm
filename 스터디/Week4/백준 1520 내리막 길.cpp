// 내리막길:성공
#include <iostream>
#include <cstdio>
#include <cstring>

#define SIZE 500

int m, n;
int map[SIZE][SIZE];
int dp[SIZE][SIZE]; //x,y를방문했는지 했으면 경로의 개수 저장
int uphill[SIZE][SIZE][4];// (x,y)에서 상하좌우 중 오르막길인 곳 (상, 하, 좌, 우)

// (n-1,m-1)에서 시작해서 (0,0)에 도달하면 return 1
// (x,y)에서 오르막길인 곳 찾기
void find(int x,int y) {
    //downhill배열 0으로 초기화
    for(int i=0; i<4; i++)
        uphill[x][y][i]=0;
    // 윗쪽 확인 (오르막길이면 downhill[0]=1)
    if(x!=0&&map[x][y]<map[x-1][y])
        uphill[x][y][0]=1;
    // 아랫쪽 (오르막길이면 1)
    if(x!=n-1&&map[x][y]<map[x+1][y])
        uphill[x][y][1]=1;
    // 왼쪽
    if(y!=0&&map[x][y]<map[x][y-1])
        uphill[x][y][2]=1;
    //오른쪽
    if(y!=m-1&&map[x][y]<map[x][y+1])
        uphill[x][y][3]=1;


}

int move(int x, int y) {
    // 0,0이면 종료
    if(x==0&&y==0)
        return 1;
    //이미 방문했으면
    if(dp[x][y]!=-1)
        return dp[x][y];
    //방문했음을 표시
    dp[x][y]=0;
    // 해당 좌표의 상하좌우 조사
    find(x,y);

    //윗쪽으로 가는 경우
    if(uphill[x][y][0]==1) {

        dp[x][y]+=move(x-1,y);
    }
    //아래로가는경우
    if(uphill[x][y][1]==1) {

        dp[x][y]+=move(x+1,y);
    }
    // 왼쪽으로
    if(uphill[x][y][2]==1) {

        dp[x][y]+=move(x,y-1);
    }
    // 오른쪽으로
    if(uphill[x][y][3]==1) {

        dp[x][y]+=move(x,y+1);
    }

    return dp[x][y];
}

int main() {
    scanf("%d", &n);
    scanf("%d", &m);
    std::memset(dp, -1, sizeof(dp));

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++)
            std::cin>>map[i][j];
    }

    int ans = move(n-1,m-1);
    std::cout<<ans;
    return 0;
}
