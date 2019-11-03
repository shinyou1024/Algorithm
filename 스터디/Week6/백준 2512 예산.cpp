// 예산 : 우선순위 큐와 노가다 사용
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define SIZE 10000
using namespace std;
int budget; // 총예산
int n; // 요청수
int demand_sum; //요청예산의총합
priority_queue<int, vector<int>, greater<int> > demand;
int budget_left; // 몇몇 요청을 해결한 후의 나머지 예산
int min_budget; // 상한액



//q는 예산이 할당되지 않은 요청들의 큐임 (내림차순)
void solve(priority_queue<int, vector<int>, greater<int> > q) {

       // 변수 초기화
       int i = q.size();  // 아직 할당되지 않은 예산요청의 수
       min_budget=budget_left/i; // 임시 상한액 (남은 예산을 평균낸 거)
       int sum = 0; // 임시 상한액보다 작은 요청금액의 합
       int count = 0; // 임시 상한액 작은 요청의 수

       // 종료조건 : q에서 임시상한액보다 작은 게 없으면 재귀 끝 (count가 0이면)
       // 임시 상한액보다 적은 요청을 다 해결(pop)한 다음 break
       // 요청을 해결할 때 sum에 해결한 요청금액의 합을 저장하고, count도 늘려줌
       while(true) {
           if(min_budget>q.top()) {
               sum += q.top();
               q.pop();
               count++;
           }
           else if(count==0)
               return;
           else
               break;
       }
       budget_left -= sum; // 남은 금액 조정
       solve(q); // 임시 상한액보다 커서 해결못한 요청들을 가지고 재귀함수돌리기

}



int main() {
   //입력 및 초기화
   cin>>n;
   for(int i=0; i<n; i++) {
       int a;
       cin>>a;
       demand.push(a);
       demand_sum+=a;
   }
   cin>>budget;
   budget_left = budget;

   // 예산이 모든 요청을 만족시키면 그 중 가장 큰 것 출력
   if(demand_sum<=budget) {
       while(demand.size()!=1)
           demand.pop();
       cout<<demand.top();
   }
   else {
       solve(demand);
       cout<<min_budget;
   }
   return 0;

}
