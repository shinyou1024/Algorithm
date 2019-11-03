/*
 1535 안녕
 분류 :dp
 노트 : bottom up방식으로 풀면 dp[x][1]에 정답이 쌓임
 */
/*
#include <iostream>
#include <string.h>
#include <algorithm>
#define SIZE 21
using namespace std;
int n;
int lose[SIZE];
int gain[SIZE];
int hp=100;
int memo[101][SIZE]; // dp[i][j] : 체력이 i일 때 j번까지 인사했을 때의 기쁨

int dp(int h, int num) {
    // 기저사례 : 범위 초과
    if(num>n)
        return 0;

    int& ret = memo[h][num];
    if(ret!=-1)
        return ret;

    // num번째 사람과 인사 안 할 경우
    ret = dp(h, num+1);

    // 인사할 경우 : 인사 안 하는 경우와 비교해서 더 큰 값 저장
    if(h-lose[num]>0)
        ret = max(ret, dp(h-lose[num], num+1)+gain[num]);
    return ret;
}

int main() {
    cin>>n;
    for(int i=1; i<=n; i++)
        cin>>lose[i];
    for(int i=1; i<=n; i++)
        cin>>gain[i];
    memset(memo, -1, sizeof(memo));

    cout<<dp(100, 1);


    return 0;
}
