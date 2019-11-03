/*
 그 전의 숫자가 뭔지를 어떻게 전해줄지
 */
/*
#include <iostream>
#include <string.h>
#define SIZE 101
using namespace std;

int T;
int n, k;
int memo[SIZE][SIZE][2]; // memo[i][j][k] : 길이가 i일 때, j만큼의 인접비트수를 가지고

// next : 수열의 다음 번 숫자
int dp(int len, int num, int bit) {
    cout<<len<<","<<num<<","<<bit<<endl;
    // 기저 사례
    if(idx>=n)
        return 0;
    //메모이제이션
    int& ret = memo[idx][here];
    if(ret!=-1)
        return ret;
    cout<<"하"<<endl;
    if(here==1&&next==1) {
        cout<<"?"<<endl;
        ret = 1;
    }
    else
        ret = 0;
    for(int i=0; i<2; i++) {
        ret += dp(idx+1, 0, i) + dp(idx+1, 1, i);
    }
    cout<<"ret:"<<ret<<endl;
    return ret;
}

int main() {
    cin>>T;
    for(int i=0; i<T; i++) {
        memset(memo, -1, sizeof(memo));
        cin>>n>>k;
        dp(1,0,0);
        dp(1,0,1);
        dp(1,1,0);
        dp(1,1,1);
        cout<<memo[1][0]+memo[1][1]<<endl;
    }
    return 0;
}
