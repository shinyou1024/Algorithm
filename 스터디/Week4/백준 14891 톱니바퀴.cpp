// 14891: 톱니바퀴:성공
#include <stdio.h>
#include <iostream>
using namespace std;


int k;//회전횟수
int num;//주어지는 바퀴번호
int direction;//주어지는 회전방향
int score=0;
int gear[4][8];
//맞닿는 부분의 극이 서로 다르면 true.
bool t01;
bool t12;
bool t23;

//회전했었는지 했으면 1, 안했으면 0
int ex[4];

// 맞닿는 부분의 극이 같은지 확인
void check (int arr[][8]){
    if(arr[0][2]!=arr[1][6]) {
        t01 = true;
    }
    if(arr[1][2]!=arr[2][6]) {
        t12 = true;
    }
    if(arr[2][2]!=arr[3][6]) {
        t23 = true;
    }

}

// 회전 함수
void rotate(int arr[][8], int n, int d){
    //시계방향회전
    if(d==1) {
        //cout<<n+1<<"번째"<<"시계회전"<<endl;
        int last = arr[n][7];
        for(int i=6; i>=0; i--) {
            arr[n][i+1]=arr[n][i];
        }
        arr[n][0]=last;

    }
    // 반시계방향회전
    else if(d==-1) {
        //cout<<n+1<<"번째"<<"반시계회전"<<endl;
        int first = arr[n][0];
        //두번째원소부터 마지막원소까지 왼쪽으로 이동
        for(int i=1; i<8; i++) {
            arr[n][i-1]=arr[n][i];
        }
        //복사해둔 마지막 원소를 마지막자리에 넣기
        arr[n][7]=first;
    }
}

// 톱니바퀴 작동
void operate(int arr[][8], int n, int d) {
    // 시계방향회전일때
    if(d==1) {
        // 첫 번째 톱니바퀴
        if(ex[n]==0&&n==0) {
            // 일단 회전했는지 여부 표시해줌 => 한 번만 회전시키기 위해서
            ex[n]=1;
            // 두 번째 톱니바퀴와 맞닿는 부분의 극이 다르면
            if(t01==true)
                // 두 번째 톱니바퀴 작동 => 인접한 톱니바퀴 확인 & 해당 톱니바퀴 회전(안 돌았으면)
                operate(arr, 1, -1);
            // 원래 돌리려던 첫 번째 톱니바퀴 회전
            rotate(arr, 0, 1);
            }
        // 두 번째 톱니바퀴
        else if(ex[n]==0&&n==1) {
            ex[n]=1;
            if(t01==true)
                operate(arr, 0, -1);
            if(t12==true)
                operate(arr, 2, -1);
            rotate(arr, 1, 1);
        }
        // 세 번째 톱니바퀴
        else if(ex[n]==0&&n==2) {
            ex[n]=1;
            if(t12==true)
                operate(arr, 1, -1);
            if(t23==true)
                operate(arr, 3, -1);
            rotate(arr, 2, 1);
        }
        //네 번째 톱니바퀴
        else if(ex[n]==0&&n==3) {
            ex[n]=1;
            if(t23==true)
                operate(arr, 2, -1);
            rotate(arr, 3, 1);
        }
    }
    if(d==-1) {
        if(ex[n]==0&&n==0) {
            ex[n]=1;
            if(t01==true)
                operate(arr, 1, 1);
            rotate(arr, 0, -1);
        }
        else if(ex[n]==0&&n==1) {
            ex[n]=1;
            if(t01==true)
                operate(arr, 0, 1);
            if(t12==true)
                operate(arr, 2, 1);
            rotate(arr, 1, -1);
        }
        else if(ex[n]==0&&n==2) {
            ex[n]=1;
            if(t12==true)
                operate(arr, 1, 1);
            if(t23==true)
                operate(arr, 3, 1);
            rotate(arr, 2, -1);
        }
        else if(ex[n]==0&&n==3) {
            ex[n]=1;
            if(t23==true)
                operate(arr, 2, 1);
            rotate(arr, 3, -1);
        }
    }
}

int main(int argc, const char * argv[]) {

    //입력
    for(int i=0; i<4; i++) {
        for(int j=0; j<8; j++) {
            scanf("%1d", &gear[i][j]);
        }
    }
    cin>>k;
    for(int i=0; i<k; i++) {
        t01 = false;
        t12 = false;
        t23 = false;
        for(int i=0; i<4; i++) {
            ex[i]=0;
        }
        check(gear);
        cin>>num>>direction;

        operate(gear, num-1, direction);
        /*
        for(int i=0; i<8;i++) {
            cout<<gear[0][i];

        }
        cout<<"/"<<endl;
        for(int i=0; i<8;i++) {
            cout<<gear[1][i];

        }
        cout<<"/"<<endl;
        for(int i=0; i<8;i++) {
            cout<<gear[2][i];

        }
        cout<<"/"<<endl;
        for(int i=0; i<8;i++) {
            cout<<gear[3][i];

        }
        cout<<"/"<<endl;
         */
        /*
    }




    // 점수 매기기
    if(gear[0][0]==1)
        score=1;
    if(gear[1][0]==1)
        score+=2;
    if(gear[2][0]==1)
        score+=4;
    if(gear[3][0]==1)
        score+=8;

    cout<<score<<endl;
}
