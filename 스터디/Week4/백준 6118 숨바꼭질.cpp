// 6118: 숨버꼭질

#include <stdio.h>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>


int n;
int m;
int r; // 행
int c; // 열
int min_shed; // 최단거리인 헛간의 번호
int count=0;

std::vector<std::vector<int> > adj;
std::vector<int> distance;
std::vector<int> parent;


void bfs(int start, std::vector<int>& distance, std::vector<int>& parent) {
    distance = std::vector<int>(adj.size(), -1);
    parent = std::vector<int>(adj.size(), -1);
    std::queue<int> q; // 방문할 정점 목록을 유지하는 큐
    distance[start] = 0;
    parent[start] = start;
    q.push(start);

    while (!q.empty()) {
        int here = q.front();
        q.pop();
        // here의 모든 인접한 정점을 검사한다.
        for (int i = 0; i < adj[here].size(); ++i) {
            int there = adj[here][i];
            // 처음 보는 정점이면 방문 목록에 집어넣는다.
            if (distance[there] == -1) {
                q.push(there);
                distance[there] = distance[here] + 1;
                parent[there] = here;
            }
        }
    }
}

// v로부터 시작점까지의 최단 경로를 계산한다.
std::vector<int> shortestPath(int v, const std::vector<int>& parent) {
    std::vector<int> path(1, v);
    while (parent[v] != v) {
        v = parent[v];
        path.push_back(v);
    }
    reverse(path.begin(), path.end());
    return path;
}
int main(int argc, const char * argv[]) {
    std::cin>>n>>m;
    adj.assign(n, std::vector<int>(n, 0));
    // cout<<"/"<<endl;

    for(int i=0; i<m; i++) {
        std::cin>>r;
        std::cin>>c;
        adj[r-1][c-1]=1;
        adj[c-1][r-1]=1;
    }
    bfs(0, distance, parent);
    for(int i=1; i<n; i++) {
        shortestPath(i, parent);
    }

    min_shed = 1;
    for(int i=2; i<n; i++) {
        if(min_shed>distance[i]) {
            min_shed=i;
        }
    }

    for(int i=1; i<n&&i!=min_shed; i++) {
        if(distance[min_shed]==distance[i])
            count++;
    }

    std::cout<<min_shed-1<<" "<<distance[min_shed]+3<<" "<<count;

    /*
    for(int i=0; i<adj.size(); i++) {
        for(int j=0; j<adj.size();j++) {
            std::cout<<adj[i][j];
        }
        std::cout<<"/"<<std::endl;
    }
  */



   /*

}
*/

/*
 // 숨바꼭질:실패

#include <stdio.h>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n;
int m;
int a; // 인접리스트생성시에필요
int b; // 인접리스트생성시에필요
int max_shed; // 최장거리인 헛간의 번호


// 그래프의 인접 리스트 표현
vector<vector<int> > adj;
// 각 정점을 방문했는지 여부를 나타낸다.
vector<bool> visited;

vector<int> dist;

void dfs(int here) {
    cout << "DFS visits " << here << endl;
    visited[here] = true;

    // 모든 인접 정점을 순회하면서
    for (int i = 0 ; i < adj[here].size(); ++i) {
        int there = adj[here][i];
        // 아직 방문한 적 없다면 방문한다.
        if (!visited[there])
            dfs(there);
    }
    // 더이상 방문할 정점이 없으니, 재귀호출을 종료하고 이전 정점으로 돌아간다.
}


// 모든 정점을 방문한다.
void dfsAll() {
    // visited를 모두 false로 초기화한다.
    visited = vector<bool>(adj.size(), false);
    // 모든 정점을 순회하면서 아직 방문한 적 없으면 방문한다.
    for (int i = 0; i < adj.size(); ++i)
        if (!visited[i])
            dfs(i);
}


int main(int argc, const char * argv[]) {

        std::cin>>n>>m;
        adj.assign(n, std::vector<int>(n, 0));
        // cout<<"/"<<endl;

    // 인접행렬 입력
    /*
        for(int i=0; i<m; i++) {
            std::cin>>r;
            std::cin>>c;
            adj[r-1][c-1]=1;
            adj[c-1][r-1]=1;
        }
    */
    /*
    // 인접리스트 입력
    for(int i=0; i<m; i++) {
        std::cin>>a;
        std::cin>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }






        // 최소거리
        max_shed = 1;
        for(int i=2; i<n; i++) {
            if(max_shed<dist[i]) {
                max_shed=i;
            }
        }

        int count = 0;
        for(int i=1; i<n&&i!=max_shed; i++) {
            if(dist[max_shed]==dist[i])
                count++;
        }

        std::cout<<max_shed-1<<" "<<dist[max_shed]+3<<" "<<count;

        /*
         for(int i=0; i<adj.size(); i++) {
         for(int j=0; j<adj.size();j++) {
         std::cout<<adj[i][j];
         }
         std::cout<<"/"<<std::endl;
         }
         */
/*
    return 0;
}
