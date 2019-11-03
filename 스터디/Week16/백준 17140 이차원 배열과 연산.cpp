/*
- width : 최대 열의 길이 / height : 최대 행의 길이

풀이방식 (R 연*)
  - 벡터 v : {등장 횟수, 숫자} 순으로
  - cnt : 각 숫자의 등장 횟수를 일단 담아두기 => 초기화 필수!
  - q : 등장한 숫자들을 담아두자

  1. 각 행을 돌면서 처음 등장한 숫자면 q에 push
  2. cnt[]에 각 숫자가 몇 번 등장했는지를 기록한다
  3. 기록이 끝나면, q에 있는 숫자들을 지표로 cnt[]를 참조하여 벡터에 {등장횟수, 숫자} 순으로 넣어준다
  4. 등장횟수를 기준으로 v 정렬
  5. v를 토대로 행을 채워준다 (v의 한 원소는 pair로 이루어져 있으니까 map의 두 칸씩 채워짐=> 2*j와 2*j+1을 채워주는 것!)
  6. 1~6을 반복하는 동안 가장 많은 숫자가 등장한 행을 tmp에 넣어준다 (2배 해야함!!=>5번과 같은 이유)
    => 모든 업데이트가 끝나면 width를 tmp로 바꿔준다.

  - C연산에서는 map[j][i]를 조사해야함

오답노트
  1. 각 칸을 조사할 때 0으로 바꾸주기 => 따로 칸을 비워줄 필요가 없다
  2. C연산에서 map[j][i]을 조사해야 함
  3. 어차피 행끼리는 영향을 주지 않으므로 그냥 행마다 조사하면서 바로 업데이트 해도 됨
  4. main함수의 while문에서
    0초에 바로 답을 찾는 경우도 있으므로(원래 배열이 그렇게 주어진 경우) 답을 찾는 조건검사를 제일 먼저 해 주어야 함
*/
#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int r, c, k;
int width=3, height=3; // 최대 행, 열 길이
int map[110][110];
void R();
void C();
void print();
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> r >> c >> k;
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++)
            cin >> map[i][j];
    }
    int t = 0;

    while(t<=100) {
        if(map[r-1][c-1] == k)
            break;
        t++;
        if(height>=width)
            R();
        else
            C();
        //print();

    }
    if(t>100)
        cout<<-1;
    else
        cout<<t;
    return 0;
}

void erase() {
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            map[i][j] = 0;
        }
    }
}
void R() {
    int tmp=width;
    // 번호 채우기
    for(int i=0; i<height; i++) {
        vector<pair<int, int> > v;
        int cnt[110];
        memset(cnt, 0, sizeof(cnt));
        queue<int> q;
        for(int j=0; j<width; j++) {
            int x = map[i][j];
            map[i][j] = 0; // 바로바로 지워주기!
            if(x==0)
                continue;
            if(cnt[x]==0)
                q.push(x);
            cnt[x]++;
        }

        while(!q.empty()) {
            int x = q.front();
            q.pop();
            v.push_back({cnt[x], x});
        }
        sort(v.begin(), v.end());
        if(tmp<v.size()*2)
            tmp = v.size()*2;
        for(int j=0; j<v.size(); j++) {
            map[i][2*j] = v[j].second;
            map[i][2*j+1] = v[j].first;
        }
    }
    width = tmp;
}

void C() {
    int tmp=height;
    // 번호 채우기
    for(int i=0; i<width; i++) {
        vector<pair<int, int> > v;
        int cnt[110];
        memset(cnt, 0, sizeof(cnt));
        queue<int> q;
        for(int j=0; j<height; j++) {
            int x = map[j][i];
            map[j][i] = 0;
            if(x==0)
                continue;
            if(cnt[x]==0)
                q.push(x);
            cnt[x]++;
        }

        while(!q.empty()) {
            int x = q.front();
            q.pop();
            v.push_back({cnt[x], x});
        }
        sort(v.begin(), v.end());
        if(tmp<v.size()*2)
            tmp = v.size()*2;

        for(int j=0; j<v.size(); j++) {
            map[2*j][i] = v[j].second;
            map[2*j+1][i] = v[j].first;

        }
    }
    height = tmp;
}

void print() {
    cout<<"============================"<<endl;
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++)
            cout<<map[i][j];
        cout<<"\n";
    }
}
