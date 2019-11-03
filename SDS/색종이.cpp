#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;
struct Color{
    int prv;
    int nxt;
    int pass_prv;
    int pass_nxt;
    int cnt;
};
int T, n, k;
int arr[10000+2];
Color color[10000];

void init() {
    for(int i=0; i<=k; i++) {
        color[i].cnt = 0;
        color[i].prv = 0;
        color[i].nxt = 0;
        color[i].pass_prv = 0;
        color[i].pass_nxt = 0;
    }
    memset(arr, 0, sizeof(arr));
}
void run() {

    int zero = 0; // 0의 개수
    int now = 0;
    for(int i=0; i<=n; i++) {
        int num = arr[i];

        if(i==n) {
            color[now].nxt = zero;
            if(now<k) {
                color[now].pass_nxt = k - now;
            }
        }
        else if(num==0) {
            zero++;
        }
        // 숫자를 건너뛰었으면
        else if(num>now) {
            // 건너뛴 경우
            if(num>now+1) {
                color[now].nxt = zero;
                color[now].pass_nxt = num-now-1;
                color[num].prv = zero;
                color[num].pass_prv = num-now-1;
                zero = 0;
                now = num;
            }
            // 원래 나와야하는 숫자면
            else {
                color[now].nxt = zero;
                color[num].prv = zero;
                zero = 0;
                now = num;
            }
        }
        // 같은 숫자면
        else if(num==now) {

            color[num].cnt += zero;
            zero = 0;
        }
    }
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);

    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        init();
        cin >> n >> k;
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        for (int i = 0; i < n; i++) {
            color[arr[i]].cnt++;
        }

        run();

        int max = 0;
        for(int i=1;i<=k; i++) {
            if(color[0].cnt == n) {
                max = n-k+1;
                break;
            }
            if(color[i].cnt == 0)
                continue;
            int sum = color[i].cnt + (color[i].prv - color[i].pass_prv) + (color[i].nxt - color[i].pass_nxt);
            if(sum > max)
                max = sum;
        }

        cout << '#' << tc << ' ' << max<<'\n';
    }



    return 0;
}
