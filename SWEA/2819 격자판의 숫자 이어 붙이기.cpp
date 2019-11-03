#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
// (홀수 자리의 합 x 3) + 짝수 자리의 합 + 검증 코드가 10의 배수
int T;
int map[4][4];
int dy[]={-1, 0, 1, 0};
int dx[]={0, 1, 0, -1};
int ans;
int visit[10000000]; // 해당 숫자가 나왔는지
void init() {
    ans = 0;
    memset(visit, 0, sizeof(visit));
}
void dfs(int depth, int y, int x, int num) {
    //cout <<"dfs("<<depth<<", "<<y<<", "<<x<<", "<<num<<")"<<endl;
    if(depth==0) {
        if(!visit[num]) {
            visit[num] = 1;
            ans++;
        }
        return;
    }
    else {
        for(int i=0; i<4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny<0 || ny>3 || nx<0 || nx>3)
                continue;
            int tmp = num;
            num += pow(10, depth-1) * map[ny][nx];
            dfs(depth-1, ny, nx, num);
            num = tmp;
        }
    }
}

int main() {
    cin >> T;
    for(int tc=1; tc<=T; tc++) {
        init();
        for(int i=0; i<4; i++) {
            for(int j=0; j<4; j++)
                cin >> map[i][j];
        }

        for(int i=0; i<4; i++) {
            for(int j=0; j<4; j++) {
                int num = map[i][j] * 1000000;
                dfs(6, i, j, num);
            }
        }

        cout << '#' << tc <<' '<<ans<<'\n';
    }
    return 0;
}
