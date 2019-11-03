#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#define INF 100000000

using namespace std;
// x와 y좌표를 저장하는 구조체
struct block {
    int block_cost;
    int x;
    int y;
    bool operator <(block a)const {
        return block_cost<a.block_cost;
    }

};


int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int t;
int n;
int v;
int cave[126][126];
// n은 한 행의 길이
// src는 (0,0)의 가중치
int dijkstra(int n) {
    // (0,0)에서 (i, j)까지의 최단거리를 저장
    int dist[126][126];
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++)
            dist[i][j]=INF;
    }
    dist[0][0]=0;

    priority_queue<block> pq;
    // 좌표를 저장할 position 객체 생성
    block p;
    p.x = 0;
    p.y = 0;
    p.block_cost=0;
    // 큐에 (0,0)의 좌표와 가중치 저장
    pq.push(p);
    while(!pq.empty()) {
        block here = pq.top();
        //cout<<"here:"<<here.x<<","<<here.y<<endl;
        int cost = -pq.top().block_cost;
        //cout<<"cost:"<<cost<<endl;
        pq.pop();
        // 꺼낸 것보다 더 짧은 경로를 알고 있다면 지금 꺼낸 건 무시
        if(dist[here.x][here.y]<cost)
            continue;
        // 인접한 칸을 검사
        for(int i=0; i<4; i++) {
            int newX=here.x+dx[i];
            int newY=here.y+dy[i];
            if(newX<0 || newX>n-1 || newY<0 || newY>n-1)
                continue;
            block there;
            there.x = newX;
            there.y = newY;
            there.block_cost = cave[newX][newY];
            //cout<<there.x<<","<<there.y<<":"<<endl;
            int nextDist = cost + there.block_cost;
            //cout<<"nextDist:"<<nextDist<<endl;
            if(dist[newX][newY]>nextDist) {
                //cout<<"오키"<<endl;
                dist[newX][newY]=nextDist;
                there.block_cost = -nextDist;
                pq.push(there);



        }


    }
    }
    return dist[n-1][n-1]+cave[0][0];
}

int main() {
    int index = 1;
    while(true) {
        cin>>n;
        if(n==0)
            break;
        else {
            for(int i=0; i<n; i++) {
                for(int j=0; j<n; j++) {
                    cin>>cave[i][j];
                }
            }


            cout<<"Problem "<<index<<": "<< dijkstra(n)<<endl;
            index++;
        }
    }
    return 0;
}
