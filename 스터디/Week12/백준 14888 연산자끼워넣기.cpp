#include <iostream>

int n;
int num[12];
int oper[4];
int min=1000000000;
int max=-1000000000;
// idx : 숫자의 인덱스, res : 계산한 값, add~divd : 각 연산마다 남은 개수
void solve(int idx, int res, int add, int sub, int mul, int divd) {
    if(idx==n-1) {
        if(res<min)
            min = res;
        if(res>max)
            max = res;
        return;
    }
    if(idx>n)
        return;
    // 덧셈
    if(add-1>=0)
        solve(idx+1, res+num[idx+1], add-1, sub, mul, divd);
    // 뺄셈
    if(sub-1>=0)
        solve(idx+1, res-num[idx+1], add, sub-1, mul, divd);
    // 곱셈
    if(mul-1>=0)
        solve(idx+1, res*num[idx+1], add, sub, mul-1, divd);
    // 나눗셈
    if(divd-1>=0&&num[idx]!=0)
        solve(idx+1, res/num[idx+1], add, sub, mul, divd-1);
}

int main() {
    std::cin>>n;
    for(int i=0; i<n; i++) {
        std::cin>>num[i];
    }
    for(int i=0; i<4; i++) {
        std::cin>>oper[i];
    }
    solve(0, num[0], oper[0], oper[1], oper[2], oper[3]);
    std::cout<<max<<'\n';
    std::cout<<min<<'\n';
}
