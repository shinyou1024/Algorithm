#include <stdio.h>
#include <iostream>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;

int n, k;

vector<int> prime;
// 에라토스테네스의 체 : x까지의소수를 모두 prime에 푸쉬백
void erato(int x) {
    prime.push_back(1);
    int arr[x];
    for(int i=2; i<=x; i++) {
        arr[i]=i;
    }
    for (int i=2; i<=sqrt(x); i++) {
       if(arr[i]==0)
           continue;
        for(int j=i*i; j<=x; j+=i) {
            arr[j]=0;
        }
    }

    for(int i=2;i<=x; i++) {
        if(arr[i]!=0)
            prime.push_back(i);
    }

}
int solve(int x) {
    vector<int> output;

    // x를 에라토스테네스의 체의 첫요소부터 차례대로 나눠서 나누어떨어지는 걸 output에 넣기
    int i=0;
    while(i<prime.size()) {
        if(prime[i]>x)
            break;
        if(x%prime[i]==0) {
            //cout<<prime[i]<<"는"<<x<<"의 소인수임"<<endl;
            output.push_back(prime[i]);
        }
        i++;
    }

    // 소인수중 최댓값이 k보다 작거나같으면 1 / 아니면 0반환
    int max = output.back();
    if(max<=k)
        return 1;
    else
        return 0;

}

int main() {
    cin>>n>>k;
    // 에라토스테네스의 체를 실행해서 n이하의 소수로 이루어진 벡터 생성
    erato(n);
    int count=k; //k보다 작은 수들은 k세준수이기때문에 k로 초기화해줌
    // k+1부터 n까지 세준수 세기
    for(int p=k+1; p<=n; p++) {
        //cout<<p<<"시작"<<endl;
        count+=solve(p);
    }
    cout<<count;
    return 0;
}
