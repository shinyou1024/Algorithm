#include <iostream>
#include <string>
using namespace std;
int memo[5001]; //
int num[5001];
string input;
int main() {
    cin>>input;
    // 입력받은 값을 int배열에 넣기
    for(int i=1; i<input.length(); i++) {
        num[i]=input[i-1]-'0'; // 아스키
    }
    memset(memo, 0, sizeof(memo));
    memo[0]=1;
    // dp
    for(int i=1; i<=input.length(); i++) {
        // 한자리수로 해석
        if(1<=num[i] && num[i]<=9)
            memo[i] = (memo[i] + memo[i-1])%1000000;
        if(i==1)
            continue;
        // 두자리 수로 만들어주기
        int two = num[i-1]*10 + num[i];
        if(10<=two && two<=26)
            memo[i] = (memo[i] + memo[i-2])%1000000;

    }
    cout<<memo[input.length()];
    return 0;
}
