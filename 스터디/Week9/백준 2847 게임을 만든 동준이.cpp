#include <iostream>
using namespace std;
int n;
int d[9];
int w[9];
int memo[9][9]; // i번째 계란으로 j번째 계란을 칠 때 최댓값
int dp(int idx, int rcv) {
    if(idx>n-1)
        return 0;
    int& ret = memo[idx][rcv];
    if(ret!=-1)
        return ret;

    d[idx] -= w[rcv];
    d[rcv] -= w[idx];

    if(d[idx]<=0)
        dp(idx+1, idx+2);
    if(d[idx+1]<0)
        dp(idx, rcv+1);
    else {
        ret = max(ret+dp(idx+1, rcv), dp(idx, rcv+1));

    }

    return ret;
}

int main() {
    cin>>n;
    for(int i=0; i<n; i++) {
        cin>>d[i]>>w[i];

    }
    dp(0,1);

    return 0;
}
