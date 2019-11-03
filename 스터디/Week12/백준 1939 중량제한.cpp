/*
 오답노트
 1. 44번째줄 : cost <= mid로 해서 오답
 (mid가 중량제한이 아니라 중량그자체이기 때문에 다리에서 mid만큼을 견딜 수 있는지를 따져야함!!!!)
 메모
 1. 이분탐색은 0~최대중량으로 해도 맞고, 다리의 중량제한을 배열로 만든 데에서 탐색해도 맞음
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>
using namespace std;
int n, m;
int s, e; // 시작점, 도착점
vector<pair<int, int> > g[100001]; // i번째 섬 기준으로 (연결된 섬, 중량제한)
vector<int> w;

// mid만큼의 무게를 가진 물품을 옮길 수 있는지 여부를 반환
bool bfs(int mid) {
    queue<int> q;
    bool visit[100001];
    memset(visit, false, sizeof(visit));
    q.push(s);
    visit[s]=true;

    while(!q.empty()) {
        int now = q.front();
        q.pop();
        // 목적지까지 도달한 경우
        if(now == e)
            return true;
        for(int i=0; i<g[now].size(); i++) {
            int next = g[now][i].first;
            int cost = g[now][i].second;
            // mid 만큼의 무게를 견딜 수 있는 다리로 이어져 있으면 큐에 넣기
            if(visit[next]==false && mid<=cost) {
                visit[next] = true;
                q.push(next);
            }
        }
    }
    // 아직 리턴 안 된 건 목적지에 도달하지 못한 것
    return false;
}
int main() {
    cin >> n >> m;
    // 그래프 만들기
    for(int i=0; i<m; i++) {
        int a, b, wgt;
        cin >> a >> b >> wgt;
        // 양방향으로 만들기
        g[a].push_back(make_pair(b, wgt));
        g[b].push_back(make_pair(a, wgt));
        // w에 중량제한 추가해주기
        w.push_back(wgt);
    }
    cin >> s >> e;
    sort(w.begin(), w.end());

    // 이분탐색
    int l = 0, r = m-1;
    while(l<=r) {
        int mid = (l+r)/2;
        // mid의 중량으로 건널 수 있으면 더 큰 중량도 견딜 수 있는지 확인
        if(bfs(w[mid]))
            l = mid + 1;
        // 못 건너면 중량을 적게해서 찾기
        else
            r = mid - 1;
    }
    cout << w[r];
    return 0;
}
