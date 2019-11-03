/*
 백준 16988 : Baaaaaaaaaduk2 (Easy)
 분류 : BFS
 내 바둑돌을 검은돌, 상대 바둑돌을 흰돌로 생각하고 풀었음

 풀이 : 빈 칸마다 검을돌 두 개를 놓는다고 가정하고(브루트포스), 그 상황에서 죽는 흰돌의 개수를 세어준다(BFS)
    1. 빈 칸마다 검은돌 두 개를 놓는다고 가정(브루트 포스)
        => 처음에 입력받을 때 빈 칸을 미리 판별해서 for문 돌릴 때 빈칸에 바둑돌 놓는 것만 생각했음
        => 각 경우의 수마다 board에 놓았던 바둑돌을 제거하고, visited를 초기화해줘야함 (중요)
    2. BFS : 그렇게 놓인 상황에서 다시 이중for문을 돌려 흰돌을 발견하면 BFS로 죽는 흰돌개수를 세어준다
        1) 전체 브루트포스과정에서 쓰이는 visited말고 한 BFS과정에서 쓸 checked배열을 만들어줌
        2) 상하좌우를 검사한다
            - 빈칸일경우 : 아예 둘러싸이는 조건이 성립하지 않으므로 함수가 종료
            - 모서리, 검은돌, 이미검사한흰돌일 경우 : cnt++
            - 아직 검사 안 한 흰돌일 경우 : 큐에 넣고 BFS를 돌려준다! (재귀는 아니고 while문으로)
        3) 큐에 더 이상 들어갈 흰돌이 없어서 while문이 끝나면
            cnt가 몇인지 확인해서 4이면 둘러싸인 걸로 판별해서 candidate들을 싹 killed로 넣어준다
    3. 각 BFS를 통해 확보한 '죽는 흰돌개수'를 killed에 더해줌
    4. 이중 포문이 한 번 끝날 때마다 새로 계산된 killed와 ans를 비교해 더 큰 값을 ans로 갱신해준다

 오답노트
    1. DFS로 풀려고 했었는데 어디선가 꼬였음
    2. 바둑돌 두 개를 놓는 경우의 수마다 판별해야 하기 때문에 visited[k][h]를 초기화해줘야함!!!!
    3. 죽는 흰 돌 개수를 반환할 때 killed += candidate이렇게 하면 중복돼서 세어짐
    4. 검은돌 올라가는 경우를 모서리가 아닌 경우와 겹치게 검사하게 해 놔서 한 번도 검사가 안 됨...

 */

/*
#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
using namespace std;
int r, c;
int board[21][21];
vector<pair<int,int> > empty;
int dy[4]={-1, 1, 0, 0};
int dx[4]={0, 0, -1, 1};
bool visited[21][21]={0}; // 흰 돌을 방문했었는지 여부(이미 확인한애는 안 해도 됨)
int size; //
int ans;


// 죽는 흰 돌의 개수를 알려주는 bfs
int bfs(int y, int x) {
    int killed=0;  //죽인 상대 돌의 총 개수
    // 이미 방문한 점이면 리턴
    if(visited[y][x])
        return 0;

    queue<pair<int, int> > q;
    q.push(make_pair(y,x));

    visited[y][x]=true;

    bool checked[21][21]={false};
    // 죽일 후보 수
    int candidate=0;
    while(!q.empty()) {
        y = q.front().first;
        x = q.front().second;

        //cout<<y<<","<<x<<"판단"<<endl;

        checked[y][x]=true;
        candidate++;
        //cout<<"candidate"<<candidate<<endl;
        q.pop();
        int cnt=0; // 큐에서 꺼낸 돌의 상하좌우를 검색했을 때, 1이거나 이미 방문한 2일경우의 수를 셈(4면막힌것)
        for(int d=0; d<4; d++) {
            int ny = y+dy[d];
            int nx = x+dx[d];

            if(0<=ny&&ny<r&&0<=nx&&nx<c) {
                // 인접한 빈칸이 있으면 뚫린 것 => 함수 반환
                if(board[ny][nx]==0) {
                    return 0;
                }
                if(board[ny][nx]==2&&checked[ny][nx]==false) {
                    checked[ny][nx]=true;
                    visited[ny][nx]=true;
                    q.push(make_pair(ny,nx));
                    // 일단 죽일 후보에 추가해줌
                    continue;
                }
                // 1돌 또는 이미 방문된 2돌일 경우
                if(board[ny][nx]==1||checked[ny][nx]==true)
                    cnt++;
            }
            // board의 모서리일 경우
            else {
                cnt++;
            }
            // 인접한 최후의 2돌까지 왔을때 막혔다고 판별난 경우

        }

        if(cnt==4)
            killed = candidate; // 이걸 killed += candidate으로 잘못 써놔서 고생...
    }
    //cout<<"죽인것:"<<killed<<endl;
    return killed;

}
int main() {
    cin>>r>>c;
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            int input;
            cin>>input;
            board[i][j]=input;
            if(input==0) {
                empty.push_back(make_pair(i,j));
            }
        }
    }


    size = empty.size();

    // 1번 돌 두 개씩 놓기
    for(int i=0; i<size; i++) {
        int x1 = empty[i].second;
        int y1 = empty[i].first;
        board[y1][x1]=1;
        for(int j=i+1; j<size; j++) {
            int mykilled=0;
            int x2 = empty[j].second;
            int y2 = empty[j].first;
            //cout<<y1<<","<<x1<<"이랑";
            //cout<<y2<<","<<x2<<endl;
            board[y2][x2]=1;

            for(int k=0; k<r; k++) {
                for(int h=0; h<c; h++) {
                    //2돌이면 bfs돌리기
                    if(board[k][h]==2)
                        mykilled += bfs(k,h);
                }
            }
            // 더 큰 값을 ans에 저장
            ans=max(ans, mykilled);
            // 다음 수를 계산하기 위해 초기화
            board[y2][x2]=0;
            // 이거안해줘서망할뻔 : 다음 수를 계산하기 위해 방문기록 지우기
            memset(visited, 0, sizeof(visited));
        }
        // 다음 수를 계산하기 위해 초기화
        board[y1][x1]=0;
    }
    cout<<ans<<endl;

    return 0;
}
