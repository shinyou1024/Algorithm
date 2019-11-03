#include <iostream>
#include <stack>
using namespace std;
int n;
int order[1010];

int main() {
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> order[i];

    int turn = 1;
    int idx = 0;
    stack<int> s;
    int flag = 1;

    while(1) {
            if(order[idx]==turn) {
                turn++;
                idx++;
            }
            else if(!s.empty()&&s.top()==turn) {
                turn++;
                s.pop();
            }
            else {
                s.push(order[idx]);
                idx++;
            }
        // 대기열은 마지막까지 탐색했는데, turn이 끝나지 않았고, 스택의 top이 turn이 아니면 Sad
        if(idx==n&&turn!=n+1&&s.top()!=turn) {
            if(turn!=n+1) {
                flag = 0;
                break;
            }
        }
        // turn의 아이까지 간식을 먹었다
       else if(turn==n+1)
           break;
    }
    if(flag==1)
        cout<<"Nice";
    else
        cout<<"Sad";
    return 0;
}
