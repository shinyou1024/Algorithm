#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int arr[100];
int turn;
int ans;
void init() {
    ans = 0;
}
 

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    for (int tc = 1; tc <= 10; tc++) {
        cin >> turn;
        for (int i = 0; i < 100; i++) {
            cin >> arr[i];
        }


        for (int i = 0; i < turn; i++) {
            sort(arr, arr + 100);
            arr[99]--;
            arr[0]++;
            if (arr[98] > arr[99])
                swap(arr[98], arr[99]);
            if (arr[0] > arr[1])
                swap(arr[0], arr[1]);

            ans = arr[99] - arr[0];

            if (arr[99] - arr[0] == 0 || arr[99] - arr[0] == 1)
                break;
        }
        cout << '#' << tc <<' '<< ans << '\n';
    }

    return 0;
}
