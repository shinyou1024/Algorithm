//저울:실패
#include <stdio.h>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>



int n;
int m;



std::vector<bool> visited;
// 그래프의 인접 리스트 표현
std::vector<std::vector<int> > adj(n, std::vector<int>(m, 0));
std::vector<std::vector<int> > adj_rev(n, std::vector<int>(m, 0));

// start에서 시작해 그래프를 너비 우선 탐색하고 각 정점의 방문 순서를 반환한다.
std::vector<int> bfs(int start) {
   // 각 정점의 방문 여부
   std::vector<bool> discovered(adj.size(), false);
   // 방문할 정점 목록을 유지하는 큐
   std::queue<int> q;
   // 정점의 방문 순서
   std::vector<int> order;
   discovered[start] = true;
   q.push(start);

   while (!q.empty()) {
       int here = q.front();
       q.pop();
       // here를 방문한다.
       order.push_back(here);
       // 모든 인접한 정점을 검사한다.
       for (int i = 0; i < adj[here].size(); ++i) {
           int there = adj[here][i];
           // 처음 보는 정점이면 방문 목록에 집어넣는다.
           if (!discovered[there]) {
               q.push(there);
               discovered[there] = true;
           }
       }
   }

   return order;
}

// start에서 시작해 그래프를 너비 우선 탐색하고 각 정점의 방문 순서를 반환한다.
std::vector<int> bfs_rev(int start) {
   // 각 정점의 방문 여부
   std::vector<bool> discovered(adj.size(), false);
   // 방문할 정점 목록을 유지하는 큐
   std::queue<int> q;
   // 정점의 방문 순서
   std::vector<int> order;
   discovered[start] = true;
   q.push(start);

   while (!q.empty()) {
       int here = q.front();
       q.pop();
       // here를 방문한다.
       order.push_back(here);
       // 모든 인접한 정점을 검사한다.
       for (int i = 0; i < adj_rev[here].size(); ++i) {
           int there = adj_rev[here][i];
           // 처음 보는 정점이면 방문 목록에 집어넣는다.
           if (!discovered[there]) {
               q.push(there);
               discovered[there] = true;
           }
       }
   }

   return order;
}


void dfs(int here) {
   std::cout << "DFS visits " << here << std::endl;
   visited[here] = true;

   // 모든 인접 정점을 순회하면서
   for (int i = 0 ; i < adj[here].size(); ++i) {
       int there = adj[here][i];
       // 아직 방문한 적 없다면 방문한다.
       if (!visited[there])
           dfs(there);
   }
   // 더이상 방문할 정점이 없으니, 저장하고 재귀호출을 종료하고 이전 정점으로 돌아간다.

}


// 모든 정점을 방문한다.
void dfsAll() {
   // visited를 모두 false로 초기화한다.
   visited = std::vector<bool>(adj.size(), false);
   // 모든 정점을 순회하면서 아직 방문한 적 없으면 방문한다.
   for (int i = 0; i < adj.size(); ++i)
       if (!visited[i])
           dfs(i);
}


int main(int argc, const char * argv[]) {

   std::cin>>n>>m;
   //adj.assign(n, std::vector<int>(n, 0));

    // 인접리스트 입력

    for(int i=0; i<m; i++) {
        int a; // 인접리스트생성시에필요
        int b; // 인접리스트생성시에필요
        std::cin>>a;
        std::cin>>b;
        adj[a-1].push_back(b-1);
        adj_rev[b-1].push_back(a-1); //역방향
    }

   // bfs(i)를 돌려서 각 i마다 방문목록에 존재하지 않는 것들을 noCompared[]에 저장
   for(int i=0; i<n; i++){
      // std::cout<<n-bfs(i).size()-bfs_rev(i).size();

   }

    return 0;
}
