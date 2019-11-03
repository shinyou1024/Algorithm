// 모든 기울기의 개수를 구하는 것과 동일한 문제이다
// 기울기=1인 지점을 기준으로 반으로 나누면 기울기의 모양은 대칭을 이룸
// 따라서 기울기 0과 1 사이의 모든 기약분수의 개수를 cnt라 하면 답은 3 + cnt+2
// => 2부터 n까지의 수를 분모로 하는 기약분수를 찾아주면 된다
// 단, 테스트 케이스마다 서로소찾기를 하면 시간초과
// => 미리 2부터 n까지의 수를 분모로 하는 기약분수의 개수를 구해놓고 테스트케이스마다 더해주기만 하면 된다!
// 기약분수의 개수 찾는 건 '자기보다 작은 서로소의 개수'를 찾는 것과 동일함

#include <stdio.h>
using namespace std;
int C;
int n;
int num_of_s[1001]; // 2부터 n까지의 수를 분모로 하는 기약분수의 수

// a, b가 서로소인지 테스트
bool seoroso(int a, int b) {
    for(int i=2; i<=b; i++) {
        if(b%i==0 && a%i==0)
            return false;
    }
    return true;
}

// 미리 기약분수의 개수를 구해놓기
void find_seoroso() {
    for(int i=2; i<=1000; i++) {
        int cnt = 0;
        for(int j=1; j<i; j++) {
            if(seoroso(j, i))
                cnt++;
        }
        num_of_s[i]=cnt;
    }
}

int main() {
    find_seoroso();
    scanf("%d", &C);
    for(int c=0; c<C; c++) {
        scanf("%d", &n);
        int cnt = 0;
        for(int i=2; i<=n; i++) {
            cnt += num_of_s[i];
        }
        int ans = cnt*2 + 3;
        printf("%d\n", ans);
    }
    return 0;
}
