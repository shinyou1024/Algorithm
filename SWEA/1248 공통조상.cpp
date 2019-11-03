#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;
int T;
int v, e;
int ans2 = 0;
struct V{
	int parent;
	int depth;
	vector<int> child;
};
int a, b;
V node[10000];
void init() {
	for (int i = 0; i<v; i++) {
		node[i].parent = NULL;
		node[i].child.clear();
	}
	ans2 = 0;
}
// a와 b의 공통조상찾기
int ancester(int c1, int c2) {
	vector<int> a1; // 1의 조상
	vector<int> a2; // 2의 조상
	int p1 = node[c1].parent;
	a1.push_back(p1);
	while (p1 != 1) {
		p1 = node[p1].parent;
		a1.push_back(p1);
	}
	int p2 = node[c2].parent;
	a2.push_back(p2);
	while (p2 != 1) {
		p2 = node[p2].parent;
		a2.push_back(p2);
	}
	int anc = 1;
	int range1 = min(a1.size(), a2.size());
	int range2 = max(a1.size(), a2.size());
	for (int i = 0; i<range1; i++) {
		for (int j = 0; j<range2; j++) {
			if (a1[i] == a2[j]) {
				anc = a1[i];
				return anc;
			}
		}
	}
	return anc;
}
void subtree(int x) {
	ans2++;
	if (node[x].child.size() == 0) {
		return;
	}
	else if (node[x].child.size() == 1) {
		subtree(node[x].child[0]);
	}
	else if (node[x].child.size() == 2) {
		subtree(node[x].child[0]);
		subtree(node[x].child[1]);
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "r", stdin);

	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> v >> e >> a >> b;
		for (int i = 0; i<e; i++) {
			int p, c;
			cin >> p >> c;
			node[p].child.push_back(c);
			node[c].parent = p;
		}

		int anc = ancester(a, b);
		subtree(anc);
		cout << '#' << tc << ' ' << anc << ' ' << ans2 << '\n';
		init();

	}
	return 0;
}