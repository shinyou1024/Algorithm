#include <iostream>
#define SIZE 20
using namespace std;
int map[SIZE][SIZE];
int n, m;
int x, y;
int a, b;
int orders; //명령수
int direction;
/*
struct node {
    int data;
    node *next;
};

class linked_list {
public:
    node *head, *tail;
    node *top, *bottom;
    linked_list() {
        head = NULL;
        tail = NULL;
        top = head;
        bottom = tail;
    }

void add(int n) {
        node *tmp = new node; //새노드
        tmp->data = n;
        tmp->next = NULL;
        //노드가없었을경우
        if(head==NULL) {
            head = tmp;
            tail = tmp;
        }
        else {
            tail->next = tmp; //꼬리의 next는 새 노드
            tmp->next = head;
            tail = tmp;
        }
}
void east() {
    for(int i=0; i<3; i++) {
    top = top->next;
    bottom = bottom->next;
    }
}
    void west() {
        for(int i=0; i<)
    }
};
*/
/*
struct Dice {

    int num[7]={0}; //0은쓰이지않는면(인덱스맞춰주기위함)

    void bot_change(int a, int b) {
        if(map[a][b]==0)
            map[a][b]=num[6];
        else {
            num[6]=map[a][b];
            map[a][b]=0;
        }

    }
    void print() {
        cout<<x<<","<< y<<endl;
    }
    // (x,y)는 굴리기전의좌표
    void west(int a, int b) {
        if(y-1<0)
            return;
        else {
            y=y-1; //주사위의좌표바꿔주기
            int tmp = num[1];
            num[1]=num[3];
            num[3]=num[6];
            num[6]=num[4];
            num[4]=tmp;
            cout<<num[1]<<endl;
            bot_change(a, b-1);
        }
    }
    void east(int a, int b) {
        if(y+1>=m)
            return;
        else {
            y=y+1;
            int tmp = num[1];
            num[1]=num[4];
            num[4]=num[6];
            num[6]=num[3];
            num[3]=tmp;
            cout<<num[1]<<endl;
            bot_change(a, b+1);
        }
    }
    void north(int a, int b) {
        if(x-1<0)
            return;
        else {
            x=x-1;
            int tmp = num[1];
            num[1]=num[5];
            num[5]=num[6];
            num[6]=num[2];
            num[2]=tmp;
            cout<<num[1]<<endl;
            bot_change(a-1, b);
        }
    }
    void south(int a, int b) {
        if(x+1>n-1)
            return;
        else {
            x=x+1;
            int tmp = num[1];
            num[1]=num[2];
            num[2]=num[6];
            num[6]=num[5];
            num[5]=tmp;
            cout<<num[1]<<endl;
            bot_change(a+1, b);
        }
    }

};


int main() {
    cin>>n>>m>>x>>y>>orders;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++)
            cin>>map[i][j];
    }
    Dice dice;
    for(int i=0; i<orders; i++) {
        cin>>direction;
        if(direction==1)
            dice.east(x, y);
        if(direction==2)
            dice.west(x, y);
        if(direction==3)
            dice.north(x, y);
        if(direction==4)
            dice.south(x, y);
    }

    return 0;
}
