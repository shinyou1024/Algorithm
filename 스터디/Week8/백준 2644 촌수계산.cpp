/*
 2644 촌수계산
 분류 : BFS을 이용한 최단거리
 오답노트 : 자식에서 부모로 가는 경로도 고려해야 하므로 양방향그래프임 1-2면 1-2와 2-1 두 간선을 넣어줘야 함
 */
/*
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define SIZE 100
using namespace std;
vector<int> graph[101];

int n; // 사람 수 (정점수)
int m; // 부모자식관계개수(간선수)
int t1, t2; // 촌수계산할애들
int ans;


int bfs(int start, int end) {
    queue<int> q;
    // parent : 경로 저장, dist: 경로까지의 거리 저장
    vector<int> parent, dist;
    parent.resize(n+1, -1);
    dist.resize(n+1, -1);

    parent[start]=start;
    dist[start] = 0;

    q.push(start);


    while(!q.empty()) {
        int tmp = q.front();
        q.pop();
        int size = int(graph[tmp].size());
        for(int i=0; i<size; i++) {
            int now = graph[tmp][i];
            if(dist[now]==-1) {
                q.push(now);
                dist[now]=dist[tmp]+1;
                parent[now]=tmp;
            }
        }
    }
    if(dist[end]==-1)
        return false;
    else {
        ans = dist[end];
        return true;
    }
}
int main() {
    cin>>n;
    cin>>t1>>t2;
    cin>>m;

    for(int i=0; i<m; i++) {
        int u, v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(int i=1; i<=n; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    if(bfs(t1, t2))
        cout<<ans;
    else
        cout<<-1;
    return 0;

}
