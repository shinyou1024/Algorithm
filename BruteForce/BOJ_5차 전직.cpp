#include <iostream>
#include <algorithm>
using namespace std;
int n, k;
long long ans;
long long exp[3*100000+2];
int main() {
    cin >> n >> k;
    for(int i=0; i<n; i++) {
        cin >> exp[i];
    }
    sort(exp, exp+n);
    long long cnt=0;
    for(int i=0; i<n; i++) {
        if(cnt<k) {
            ans += exp[i]*cnt;
            cnt++;
        }
        else {
            ans+=exp[i]*k;
        }
    }
    cout<<ans;
    return 0;
}
