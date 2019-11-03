#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;
struct Board{
    int map[8][8];

    void rotate() {
        for(int i = 0; i < 8 / 2; i++){
            for(int j = i; j < 8-i-1; j++){
                int temp = map[i][j];
                map[i][j] = map[8-j-1][i];
                map[8-j-1][i] = map[8-1-i][8-1-j];
                map[8-1-i][8-1-j] = map[j][8-1-i];
                map[j][8-1-i] = temp;
            }
        }
    }
    void print() {
        for(int i=0; i<8; i++) {
            for(int j=0; j<8; j++)
                cout<<map[i][j]<<" "<<endl;
            cout <<'\n';
        }
    }
};
Board board[11];
int T, n, q;

void init() {

}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);

    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        init();
        cin >> n;
        for(int i=0; i<n; i++) {
            for(int r=0; r<8; r++) {
                for(int c=0; c<8; c++)
                    cin >> board[i].map[r][c];
            }
        }
        cin >> q;
        board
        int ans;
        cout << '#' << tc << ' ' << ans <<'\n';
    }



    return 0;
}




1
1 2 3 4 5 6 7 8
9 10 11 12 13 14 15 16
17 18 19 20 21 22 23 24
25 26 27 28 29 30 31 32
33 34 35 36 37 38 39 40
41 42 43 44 45 46 47 48
49 50 51 52 53 54 55 56
57 58 59 60 61 62 63 64
