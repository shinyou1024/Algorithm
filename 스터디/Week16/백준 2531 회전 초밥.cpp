/*
오답노트
 1. j=i%n이 아니라 j=i%k로 오타가 나서...틀림!

 포인트
 1. 원형리스트?배열? 아무튼 회전하므로 n-1다음의 인덱스는 0이 되어야 함
    => 포문 내에서 새로운 인덱스 j를 선언해서 n이상일 경우를 처리해 준다
 */
#include <iostream>
#include <string.h>
using namespace std;

int n, d, k, c;
int belt[33333];
int check[3010]; // 먹었는지 안 먹었는지 (ox표)


// x번째 초밥부터 시작
int brute_force(int x) {
    memset(check, 0, sizeof(check));
    int res=0; // 몇 접시 먹었는지
    for(int i=x; i<x+k; i++) {
        int j = i;

        if(j>=n)
            j = i%n;

        int now = belt[j];
        if(!check[now]) {
            res++;
            check[now] = 1;
        }
    }
    if(!check[c])
        res++;

    return res;
}

int main() {
    cin >> n >> d >> k >> c;
    for(int i=0; i<n; i++)
        cin >> belt[i];
    int max = 0;
    for(int i=0; i<n; i++) {
        int tmp = brute_force(i);
        if(tmp>max)
            max = tmp;
    }
    cout<<max;
    return 0;
}
