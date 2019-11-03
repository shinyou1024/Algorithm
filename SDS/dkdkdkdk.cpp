#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
struct Block{
    char map[8][8];
};

struct Ans{
    int min;
    vector<int> order;
};

Block block[11];
char target[8][8];
char board[8][8];
int T, n, q;
int visit[11];
int selected[4]; // 어떻게 돌릴지
char now[8][8];
vector<int> vec;
Ans ans;
//  cnt번 돌리기
void rotate(char m[8][8], int cnt) {
    for(int k=0; k<cnt; k++) {
        for(int i = 0; i < 4; i++){
            for(int j = i; j < 7-i; j++){
                int temp = m[i][j];
                m[i][j] = m[8-j-1][i];
                m[7-j][i] = m[7-i][7-j];
                m[7-i][7-j] = m[j][7-i];
                m[j][7-i] = temp;
            }
        }
    }
    memcpy(now, m, sizeof(now));
}
// 쌓기
void build(char me[8][8], int r) {
    rotate(me, r);
    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            if(now[i][j]=='.')
                continue;
            else {
                board[i][j] = now[i][j];
            }
        }
    }
}

bool check(int cnt, vector<int> o) {
    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            if(board[i][j]!=target[i][j])
                return false;
        }
    }
    if(ans.min>cnt) {
        ans.min = cnt;
        ans.order.clear();
        ans.order.assign(o.begin(), o.end());
    }
    return true;
}
void simulation(vector<int> v, int depth) {
    //v에 쌓을 순서가 들어온다
    for(int a=0; a<4; a++) {
        for(int b=0; b<4; b++) {
            for(int c=0; c<4; c++) {
                for(int d=0; d<4; d++) {
                    vector<int> o;
                    // 첫번째판
                    o.push_back(v[0]);
                    build(block[v[0]].map, a);
                    if(check(1, o))
                        return;
                    // 두번째판
                    o.push_back(v[1]);
                    build(block[v[1]].map, b);
                    if(check(2, o))
                        return;
                    o.push_back(v[2]);
                    build(block[v[2]].map, c);
                    if(check(3, o))
                        return;
                    o.push_back(v[3]);
                    build(block[v[3]].map, d);
                    if(check(4, o))
                        return;
                }
            }
        }
    }
    /*
    if(depth==4) {
        for(int i=0;i<4;i++){
            printf("%d ",selected[i]);
        }
        printf("\n");
    }

    for(int i=v[0].idx; i<v[3].idx; i++) {
        visit[depth] = i;
        simulation(v, depth+1);
    }
    // 초기화
    for(int i=v[0].idx; i<v[3].idx; i++) {
        visit[depth] = 0;
    }*/
}

void dfs(vector<int> v, int depth)
{
    if(depth==4) {
        simulation(v, 0);
    }
    for(int i=0; i<n; i++) {
        if(!visit[i]) {
            visit[i] = 1;
            v.push_back(i);
            dfs(v, depth+1);
            visit[i] = 0;
        }
    }
}




int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);

    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        cout<<'#'<<tc<<' ';
        for(int k=0; k<n; k++) {
            for(int i=0; i<8; i++) {
                for(int j=0; j<8; j++) {
                    cin >> block[0].map[i][j];
                }
            }
        }
        cin >> q;
        for(int k=0; k<q; k++) {
            for(int i=0; i<8; i++) {
                for(int j=0; j<8; j++) {
                    cin >> target[i][j];
                }
            }
            // 여기에 코드작성

            dfs(vec, 0);

            cout<<ans.min;
            for(int i=0; i<ans.order.size(); i++) {
                cout<<ans.order[i]<<' ';
            }
            //cout << '#' << tc << ' ' << ans <<' ';
        }
        cout<<'\n';

    }



    return 0;
}
