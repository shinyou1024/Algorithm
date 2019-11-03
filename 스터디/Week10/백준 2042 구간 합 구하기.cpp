#include <iostream>
using namespace std;
int n, m, k;
long long num[1000001];

long long sum(int start, long long end) {
    long long sum=0;
    for(int i=start; i<=end; i++) {
        sum += num[i];
    }
    return sum;
}
int main() {
    cin>>n>>m>>k;
    for(int i=1; i<=n; i++) {
        cin>>num[i];
    }
    for(int i=0; i<m+k; i++) {
        int a, b;
        long long c;
        cin>>a>>b>>c;
        if(a==1) {
            num[b]=c;
        }
        else {
            cout << sum(b, c)<<endl;
        }
    }
    return 0;
}
