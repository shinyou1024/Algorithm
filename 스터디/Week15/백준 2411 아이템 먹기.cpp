/*
* 상, 우로밖에 못 움직이기 때문에 아이템을 먹는 순서는 정해져있다
  (가까운 거리순)
풀이방식
 1. 아이템 좌표들 사이의 경로수를 서로 곱해주기
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

int n, m, a, b;
int memo[110][110];
int map[110][110];
vector<pair<int, int> > v; // 아이템이 있는 좌표들을 저장

void print() {
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++)
            cout<<map[i][j];
        cout<<endl;
    }
}

int dp(int y1, int x1, int y2, int x2) {
    //cout<<y1<<","<<x1<<","<<y2<<","<<x2<<endl;
    // 위, 오른쪽 방향밖에 못 가므로
    if(y1<y2 || x1>x2)
        return 0;
    if(y1==y2 && x1==x2)
        return 1;
    int &ret = memo[y1][x1];

    if(ret!=-1)
        return ret;

    ret = 0;
    // 위쪽, 오른쪽이 장애물이 아니면 가기
    if(map[y1-1][x1]!=-1)
        ret += dp(y1-1, x1, y2, x2);
    if(map[y1][x1+1]!=-1)
        ret += dp(y1, x1+1, y2, x2);

    return ret;
}

int main() {
    memset(memo, -1, sizeof(memo));
    memset(map, 0, sizeof(map));
    v.push_back({1, 1});
    v.push_back({n, m});

    cin >> n >> m >> a >> b;
    for(int i=0; i<a; i++) {
        int y, x;
        cin >> y >> x;
        map[n-y+1][x]=1;
        v.push_back({y, x});
    }
    for(int i=0; i<b; i++) {
        int y, x;
        cin >> y >> x;
        map[n-y+1][x]=-1;
    }

    cout<<v[0].first<<endl;
    sort(v.begin(), v.end());

    int ans = 1;
    for(int i=1; i<v.size()-1; i++) {
        int y1 = v[i].first;
        int x1 = v[i].second;
        cout<<y1<<","<<x1<<endl;
        int x2 = v[i+1].first;
        int y2 = v[i+1].second;
        ans *= dp(y1, x1, y2, x2);
    }
    cout<<ans;
    return 0;
}
