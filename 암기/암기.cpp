0. 격자 조합
for (int i = k; i < w*h; i++) {
	int ny = (i / (h+1));
	int nx = (i%w);
	v.push_back(Pos(ny, nx));
	dfs(depth + 1, i + 1); // 여기서 k+1이 아니라 i+1인 것 주의
	v.pop_back();
}

main 에서는 dfs(0, 0)으로 호출
1. 구조체 비교

bool op1(const Cell &a, const Cell &b) {
// 내림차순
	if (a.age > b.age)
		return true;
  // 두번째 조건
	else if (a.age == b.age)
		return a.life < b.life; // 같으면 생명력이 높은순
	else
		return false;
}

=> sort(v.begin(), v.end(), op1); // 벡터 정렬


2. 순열, 조합
// 순열
=========================================
void dfs(int depth) {
	if (depth == 5) {
		return;
	}
	else {
		for (int i = 0; i < 4; i++) {
			order[depth] = i;
			dfs(depth + 1);
		}
	}
}
========================================
int cand[];
vector<int> v;
bool visit[];
int r // 몇 개 뽑는지
void dfs(int depth) {
	if (depth == r) {
		return;
	}

	for (int i = 0; i < n; i++) {
		if (visit[i]) continue;
		visit[i] = 1;
		v.push_back(cand[i]);

		dfs(depth + 1);

		v.pop_back();
		visit[i] = 0;
	}
}

// 조합
int cand[];
vector<int> v;
int visit[];
int r // 몇 개 뽑는지
void dfs(int depth, int k) {
    if(depth==r) {
        return;
    }
    else {
        for(int i=k; i<n; i++) {
            if(visit[i]) continue;
            visit[i] = 1;
            v.push_back(cand[i]);

            dfs(depth+1, i); // k가 아니라 i!!

            visit[i] = 0;
            v.pop_back();
        }
    }
}

// 중복 순열
arr[5]={0, 1, 2, 3, 4, 5};
int order[];
int r // 몇 개 뽑는지
void dfs(int depth) {
	if (depth == r) {
		return;
	}
	// 여기서 i<12로 했었다
	for (int i = 0; i < n; i++) {
		order[depth] = arr[i];
		dfs(depth + 1);
	}
}

dfs(0);



// 중복 조합
int cand[];
vector<int> v;
int r // 몇 개 뽑는지
void dfs(int depth, int k) {
    if(depth==r) {
        return;
    }
    else {
        for(int i=k; i<n; i++) {
            select[depth] = cand[i];
            dfs(depth+1, i); // k가 아니라 i!
        }
    }
}
dfs(0, 0);

4. next_permutation 활용한 순열

vector<int> v;
// 대입
for(int i=0; i<4; i++) {
    v.push_back(i+1);
}
// 정렬
sort(v.begin(), v.end());

do{
    for(int i=0; i<v.size(); i++) {
        cout<<v[i]<<' ';
    }

} while(next_permutation(v.begin(), v.end()));


3.
ans = ans < checking() ? checking() : ans ;


5. sort

// 배열
int a[100];
sort(a, a+100);
// 벡터
sort(v.begin(), v.end());


// const와  &를 통해서 레퍼런스로 받아오는걸 잊지말자!
// x순으로 정렬하고 x값이 같으면 y순으로 각각 오른차순으로 정렬
        bool cmp(const Point &p1, const Point &p2){
            if(p1.x < p2.x){
                return true;
            }
            else if(p1.x == p2.x){
                return p1.y < p2.y;
            }
            else{
                return false;
            }
        }


6. priority_queue

#include <queue>
priority_queue<int> pq;


#include <cstdio>
#include <queue>
        using namespace std;

        struct a{
            int start;
            int end;
            int value;
        };

        bool operator<(a t, a u){
            return t.value < u.value;
        }

        priority_queue<a> pq;





        작은 놈부터 나오게 하려면 -

        * 1. operator< 구현체의 부호를 t.value > u.value로 바꾼다.

        * 2. priority_queue<a,vector<a>,greater<a> > 식으로 priority_queue를 정의한다.


#include <cstdio>
#include <queue>
        using namespace std;

        struct a{
            int start;
            int end;
            int value;
        };

        struct cmp{
            bool operator()(a t, a u){
                return t.value < u.value;
            }
        };

        priority_queue<a,vector<a>,cmp> pq;


7. 겹치는 것 없이 유닉한 숫자의 배열 만들기

sort(nums.begin(), nums.end());
nums.erase(unique(nums.begin(), nums.end()), nums.end());
