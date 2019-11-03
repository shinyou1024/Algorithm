#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Node{
    int y; int x;
};

bool operator<(const Node & a, const Node & b){
    return a.y < b.y || a.y == b.y && a.x < b.x;
}

int N, M, A, B;

bool inRge(int y, int x){
    return 1 <= y && y <= N && 1 <= x && x <= M;
}

int jido[102][102];
int dp[102][102];

vector<Node> v;

int main(){
    ios::sync_with_stdio(false);

    cin >> N >> M >> A >> B;

    int _y, _x;
    for(int i = 0; i < A; ++i){
        cin >> _y >> _x;
        if(_y == 1 && _x == 1) continue;
        if(_y == N && _x == M) continue;
        v.push_back({_y, _x});
    }
    v.push_back({1, 1});
    v.push_back({N, M});

    for(int i = 0; i < B; ++i){
        cin >> _y >> _x;
        jido[_y][_x] = 1;
    }

    sort(v.begin(), v.end());

    for(int idx = 1; idx < v.size(); ++idx){
        if(v[idx - 1].x > v[idx].x){
            cout << 0 << endl;
            return 0;
        }

        for(int cx = v[idx - 1].x + 1; cx <= v[idx].x; cx++){
            if(jido[v[idx - 1].y][cx]) {
                break;
            }
            dp[v[idx - 1].y][cx] = 1;
        }

        for(int cy = v[idx -1 ].y + 1; cy <= v[idx].y; cy++){
            if(jido[cy][v[idx - 1].x]){
                break;
            }
            dp[cy][v[idx - 1].x] = 1;
        }

        for(int cy = v[idx -1].y + 1; cy <= v[idx].y; cy++){
            for(int cx = v[idx - 1].x + 1; cx <= v[idx].x; cx++){
                if(jido[cy][cx]) continue;
                dp[cy][cx] = dp[cy - 1][cx] + dp[cy][cx - 1];
            }
        }

        if(!dp[v[idx].y][v[idx].x]){
            cout << 1 << endl;
            return 0;
        }
    }

    int ans = 1;
    for(int i = 1; i < v.size(); ++i){
        ans *= dp[v[i].y][v[i].x];
    }

    cout << ans << endl;
}
