/*
 참고 : https://sungwoo91.tistory.com/14
 풀이방식
 1. 높이순으로 정렬
 2. dp : 1) 선택안하는경우 2) 선택하고 그 다음 가능 한 경우로 재귀(파라메트릭으로 찾기)
 오답노트
  1. bs()에서 처음에 high를 n-1로 설정해주면 틀림
 */
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;


int n, s;
pair<int, int> pics[300010];
int height[300010];
int memo[300010];

// 조건을 최초로 만족시키는 인덱스 반환
int bs(int x) {
    int low = 0;
    int high = n; // n-1이면 틀림
    int mid;
    while(high>low) {
        mid = (low+high)/2;
        // 관심 x => 가능한 범위를 탐색
        if(height[mid]-height[x]<s)
            low = mid+1;
        // 관심 o => 더 앞의 인덱스가 만족시키는지 확인
        else
            high = mid;
    }
    return high;
}

int dp(int i) {
    // 종료조건
    if(i==n)
        return 0;

    int &ret = memo[i];
    if(ret !=-1)
        return ret;

    //x번째 그림을 선택하지 않는 경우
    ret = max(ret, dp(i+1));

    //x번째 그림을 선택하는 경우 => 이분탐색으로 그 다음 가능한 그림(높이 차이가 s이상)을 찾아주고 재귀
    int next = bs(i);
    ret = max(ret, dp(next) + pics[i].second);

    return ret;
}
int main() {
    memset(memo, -1, sizeof(memo));
    cin >> n >> s;
    for(int i=0; i<n; i++) {
        cin >> pics[i].first >> pics[i].second;
        height[i] = pics[i].first;
    }
    sort(pics, pics+n);
    sort(height, height+n);


    cout<<dp(0);
    return 0;
}
