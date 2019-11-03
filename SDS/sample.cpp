#include <iostream>
#include <vector>
#include <string.h>

using namespace std;
struct Block{
    char map0[8][8];
    char map1[8][8];
    char map2[8][8];
    char map3[8][8];


    void rotate(char m[8][8], int cnt) {
            for(int i = 0; i < 4; i++){
                for(int j = i; j < 7-i; j++){
                    int temp = m[i][j];
                    m[i][j] = m[8-j-1][i];
                    m[7-j][i] = m[7-i][7-j];
                    m[7-i][7-j] = m[j][7-i];
                    m[j][7-i] = temp;
                }
            }
        if(cnt==1) {
            memcpy(map1, m, sizeof(now));
        }
        if(cnt==2) {
          memcpy(map2, m, sizeof(now));
        }

        if(cnt==3) {
          memcpy(map3, m, sizeof(now));
        }
    }
};

struct Ans{
    int min;
    vector<int> order;
};





void build(char m[8][8], int r) {
    rotate(m, r);
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

void simulation(vector<int> v, int depth) {
  for(int a=0; a<4; a++) {
      for(int b=0; b<4; b++) {
          for(int c=0; c<4; c++) {
              for(int d=0; d<4; d++) {
                vector<int> o;

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
}

void dfs(vector<int> v, int depth)
{
    if(depth==4) {
        for(int i=0; i<4; i++) {
            cout<<v[i]<<' ';
        }
        cout<<'\n';
    }
    for(int i=0; i<n; i++) {
        if(!visit[i]) {
            visit[i] = 1;
            v.push_back(i);
            dfs(v, depth+1);
            visit[i] = 0;
            v.pop_back();
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
                    cin >> block[k].map0[i][j];
                }
                for(int c=1; c<=3; c++) {
                  block[k].rotate(map0, i);
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

            cout<<ans.min<<' ';
            for(int i=0; i<ans.order.size(); i++) {
                cout<<ans.order[i]<<' ';
            }

        }
        cout<<'\n';

    }



    return 0;
}
