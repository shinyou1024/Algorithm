// 로프 : 우선순위큐와 그리디 사용

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int n;
int w;
priority_queue<int> weight; // i번째 노드가 버틸 수 있는 중량
priority_queue<int> answer;



int check() {
    vector<int> max; // 가장 큰 걸 저장할 공간
    int ans;
    while(!weight.empty()) {
        // 버틸 수 있는 중량이 가장 큰 걸 저장하고 삭제
        max.push_back(weight.top());
        weight.pop();
        // 버틸수있는총무게는 n<=가장 작은 것*사용하는밧줄개수
        ans = max.back()*max.size();
        answer.push(ans);
    }
    //n, n-1, ... 1개의 로프를 사용하여 버틸 수 있는 무게중 최대값
    return answer.top();
}




int main() {
    // 입력받기
    cin>>n;
    for(int i=0; i<n; i++) {
        cin>>w;
        weight.push(w);
    }

    cout<<check();
    return 0;
}
