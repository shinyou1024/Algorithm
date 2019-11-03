/*
실패 : 메모리초과
=> 하이퍼튜브 또한 정점으로 보고 BFS를 돌린다

오답노트
1. 인접 리스트 만들 때 인덱스가 잘못되어 벡터 범위초과 발생
*/
#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;
struct State{
	int num;
	int len;
	State(int num, int len) : num(num), len(len) {}
};
int n, k, m;
vector<int> adj[100000+1];
int visit[100000+1];
int ans = INF;
void bfs();
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k >> m;
	for (int i = 0; i < m; i++) {
		vector<int> v(k);
		for (int j = 0; j < k; j++) {
			cin >> v[j];
		}

		for (int j = 0; j < k-1; j++) {
			int now = v[j];
			for (int p = j + 1; p < k; p++) {
				adj[now].push_back(v[p]);
				adj[v[p]].push_back(now);
			}
		}
	}
	bfs();
	cout << ans;


	return 0;
}

void bfs() {
	queue<State> q;
	q.push(State(1, 1));
	visit[1] = 1;
	while (!q.empty()) {
		int now = q.front().num;
		int len = q.front().len;
		q.pop();
		if (now > n) {
			continue;
		}
		if (now == n && len < ans) {
			ans = len;
			continue;
		}

		for (int i = 0; i < adj[now].size(); i++) {
			int next = adj[now][i];
			if (visit[next]) {
				continue;
			}
			else {
				q.push(State(next, len + 1));
				visit[next] = 1;
			}
		}

	}
}
