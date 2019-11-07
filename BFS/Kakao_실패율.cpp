/*
오답노트
1. double로 선언해야 함
2. 스테이지에 도달한 사람이 없을 때 ppl이 0이 되므로 0으로 나누게 되어 runtime오류
  - fail을 0으로 지정해주고 continue
*/
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
struct Rec{
    int stage; double fail;
    Rec(int stage, double fail):stage(stage), fail(fail) {}
};
double state[505];
double total;
vector<Rec> rec;
bool cmp(Rec a, Rec b) {
    if(a.fail>b.fail) return true;
    else if(a.fail==b.fail) {
        if(a.stage<b.stage) return true;
    }
    return false;
}
vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    total = stages.size();
    for(auto st:stages) {
        state[st]++;
    }
    int sum = 0;
    for(int i=1; i<=N; i++) {
        double ppl = total-sum;
        if(ppl==0) {
            rec.push_back(Rec(i, 0));
            continue;
        }
        double fail = state[i]/ppl;
        rec.push_back(Rec(i, fail));
        sum+=state[i];
    }


    sort(rec.begin(), rec.end(), cmp);
    for(auto x:rec) {
        answer.push_back(x.stage);
    }
    return answer;
}
