
// 순열
void dfs(int depth, int r, vector<int> v) {
	if (depth == 3) {
		return;
	}

	for (int i = 0; i < 3; i++) {
		if (visit[i])
			continue;
		visit[i] = 1;
		v.push_back(i);
		dfs(depth + 1, i,v);
		v.pop_back();
		visit[i] = 0;
	}
}

// 중복 순열
arr[5]={0, 1, 2, 3, 4, 5};
void dfs(int depth) {
	if (depth == n) {
		return;
	}
	// 여기서 i<12로 했었다
	for (int i = 0; i < 5; i++) {
		order[depth] = arr[i];
		dfs(depth + 1);
	}
}

dfs(0);

// 조합
