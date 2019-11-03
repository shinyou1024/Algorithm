/*
풀이방식
1. 입력받을 때 최하 패키지가격 & 최하 낱개 가격을 저장해 둠 (얘네만 필요)
2. 패키지를 최대로 샀을 때부터 낱개로만 살 경우까지 비교
오답노트
 1. 패키지로 구매하여 n개이상을 살 경우 고려 안 했음
 2. n-r이 아니라 n-r*6으로...
 */
#include <iostream>
#include<stdio.h>
#include <string.h>
using namespace std;

int n, m;
int min_p=9999;
int min_u=9999;




int main() {
    cin>>n>>m;
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        if(a<min_p)
            min_p = a;
        if(b<min_u)
            min_u=b;
    }
        int r = n/6 + 1;
        int ans=r*min_p;
        while(r--) {
            int cost = r*min_p + (n-r*6)*min_u;

            if(cost<ans)
                ans = cost;
            //cout<<cost<<endl;
        }
        cout<<ans;
    return 0;
}
