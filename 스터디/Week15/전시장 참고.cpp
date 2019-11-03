#include <iostream>
#include <algorithm>

using namespace std;

int dp[20000002];
int N, S;

int main(){
    ios::sync_with_stdio(false);
    int max_h = 0;
    cin >> N >> S;
    int h, c;
    for(int i = 0; i < N; ++i){
        cin >> h >> c;
        dp[h] = max(dp[h], c);
        max_h = max(max_h, h);
    }

    for(int i = 1; i <= max_h; ++i){
        dp[i] = max(dp[i - S > 0 ? i - S : 0] + dp[i], dp[i - 1]);
    }

    cout << dp[max_h] << endl;
}
