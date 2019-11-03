/*
 오답노트 : 포문이 많을 땐 인덱스를 조심하자
 */
/*
#include <iostream>
#include <string.h>
using namespace std;
int T;
int n;
long long ans;
long long memo[65][10]; // i번째자리가 숫자 j인 경우의 가짓수

int main() {

    for(int j=0; j<=9; j++) {
        memo[1][j]=1;
    }
    for(int i=2; i<=64; i++) {
        for(int j=0; j<=9; j++) {
            for(int k=0; k<=j; k++) {
            //cout<<i<<","<<j<<","<<k<<endl;
                memo[i][j]+=memo[i-1][k];
            }
        }
    }

        cin>>T;
    for(int i=0; i<T; i++) {
        cin>>n;
        ans = 0; // 이 부분 빼먹어서 오답이었음
        for(int s=0; s<=9; s++) {
            ans += memo[n][s]; // memo[n][i]로 잘못 써서 오답이었음
        }
        cout<<ans<<endl;
    }

    return 0;
}
