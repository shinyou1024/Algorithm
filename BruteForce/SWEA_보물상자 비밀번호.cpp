#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
struct Pos{
    int y, x, cnt;
    Pos(int y, int x, int cnt):y(y), x(x), cnt(cnt) {};
};
struct BC{
    int y, x, c, p;
    BC(int y, int x, int c, int p):y(y), x(x), c(c), p(p) {};
};
int m, a;
int dy[]={0, -1, 0, 1, 0};
int dx[]={0, 0, 1, 0, -1};
vector<int> map[15][15];
int A[105];
int B[105];
vector<BC> bc;

bool op(BC a, BC b) {
    if(a.p >= b.p) return true;
    else return false;
}

void init() {
    for(int i=1; i<=10; i++) {
        for(int j=1; j<=10; j++) {
            map[i][j].clear();
        }
    }
    bc.clear();
}
void check_range(int idx) {
    int y = bc[idx].y; int x = bc[idx].x; int c = bc[idx].c;

    queue<Pos> q;
    int visit[15][15]; memset(visit, 0, sizeof(visit));
    q.push(Pos(y, x, 0));
    visit[y][x] = 1;
    while(!q.empty()) {
        y = q.front().y; x = q.front().x; int cnt = q.front().cnt;
        q.pop();
        map[y][x].push_back(idx);
        if(cnt==c) continue;
        for(int i=1; i<=4; i++) {
            int ny = y+dy[i]; int nx = x+dx[i];
            if(ny<1 || ny>10 || nx<1 || nx>10) continue;
            if(visit[ny][nx]) continue;

            visit[ny][nx] = 1;
            q.push(Pos(ny, nx, cnt+1));
        }
    }

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    for(int tc=1; tc<=T; tc++) {
        cin >> m >> a;
        for(int i=1; i<=m; i++) cin >> A[i];
        for(int i=1; i<=m; i++) cin >> B[i];

        for(int i=0; i<a; i++) {
            int y, x, c, p;
            cin >> x >> y >> c >> p;
            bc.push_back(BC(y, x, c, p));
        }
        sort(bc.begin(), bc.end(), op);

        // map에다가 표시
        for(int i=0; i<a; i++) {
            check_range(i);
        }

        int ay = 1, ax = 1, by=10, bx=10;
        int asum=0; int bsum=0;
        for(int i=0; i<=m; i++) {
            ay = ay + dy[A[i]]; ax = ax+dx[A[i]];
            by = by + dy[B[i]]; bx = bx+dx[B[i]];
            // 둘 중 하나가 충전범위가 아닐 경우
            if(map[ay][ax].size()==0 || map[by][bx].size()==0) {
                if(map[ay][ax].size()!=0) {
                    asum += bc[map[ay][ax][0]].p;
                }
                if(map[by][bx].size()!=0) {
                    bsum += bc[map[by][bx][0]].p;
                }
            }

            // 둘 다 한 개
            else if(map[ay][ax].size()==1 && map[by][bx].size()==1) {
                int id_a = map[ay][ax][0]; int id_b = map[by][bx][0];
                // 같은 BC
                if(id_a == id_b) {
                    asum += bc[id_a].p/2;
                    bsum += bc[id_b].p/2;
                }
                // 다른 BC
                else {
                    asum += bc[id_a].p;
                    bsum += bc[id_b].p;
                }
            }
            // b의 충전 범위가 여러 개 겹침
            else if(map[ay][ax].size()==1 && map[by][bx].size()>1){
                int id_a = map[ay][ax][0]; int id_b = map[by][bx][0];
                // a, b 안 겹침
                if(id_a != id_b) {
                    asum += bc[id_a].p;
                    bsum += bc[id_b].p;
                }
                // a, b의 최대 값 겹침
                else if(id_a == id_b) {
                    // 나누는게 값이 클 경우
                    if(bc[id_a].p/2 > bc[id_a].p + bc[map[by][bx][1]].p) {
                        asum += bc[id_a].p/2; bsum += bc[id_a].p/2;
                    }
                    else {
                        asum += bc[id_a].p;
                        bsum += bc[map[by][bx][1]].p;
                    }
                }
            }
            // a는 여러개 b는 한 개
            else if(map[ay][ax].size()>1 && map[by][bx].size()==1) {
                int id_a = map[ay][ax][0]; int id_b = map[by][bx][0];
                if(id_a != id_b) {
                    asum += bc[id_a].p;
                    bsum += bc[id_b].p;
                }
                else if(id_a == id_b) {
                    // 나누는게 값이 클 경우
                    if(bc[id_a].p/2 > bc[id_b].p + bc[map[ay][ax][1]].p) {
                        asum += bc[id_a].p/2;
                        bsum += bc[id_b].p/2;
                    }
                    else {
                        bsum += bc[id_b].p;
                        asum += bc[map[ay][ax][1]].p;
                    }
                }
            }
            // 둘 다 여러개
            else {
                int id_a = map[ay][ax][0]; int id_b = map[by][bx][0];
                // a, b 안 겹침
                if(id_a != id_b) {
                    asum += bc[id_a].p;
                    bsum += bc[id_b].p;
                }
                // a, b의 최대 값 겹침
                else if(id_a == id_b) {
                    int p, q, r;
                    p = bc[id_a].p;
                    q = bc[map[ay][ax][0]].p + bc[map[by][bx][1]].p;
                    r = bc[map[ay][ax][1]].p + bc[map[by][bx][0]].p;

                    if(p>=q && p>=r) {
                        asum += bc[id_a].p/2; bsum += bc[id_b].p/2;
                    }
                    else if(q>=p && q>=r) {
                        asum += bc[map[ay][ax][0]].p; bsum += bc[map[by][bx][1]].p;
                    }
                    else if(r>=p && r>=q) {
                        asum += bc[map[ay][ax][1]].p; bsum += bc[map[by][bx][0]].p;
                    }
                }
            }
        }
        cout<<'#'<<tc<<' '<<asum+bsum<<'\n';
        init();
    }

    return 0;
}
