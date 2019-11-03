#include <iostream>
#include <string>
using namespace std;
int n;
string screen[65][65];
string result;

void compress(int y, int x, int size) {


    string color = screen[y][x];
    /*
    if(size<=1) {
        result.append(color);
        return color;
    }*/
    int cnt = 0;
    // 여기!!!
    for(int i=y; i<y+size; i++) {
        for(int j=x; j<x+size; j++) {
            //cout<<"("<<i<<","<<j<<")"<<endl;
            if(screen[i][j]==color)
                cnt++;
            else
                break;
        }
    }
    // 한 숫자로 압축되는 경우
    if(cnt==size*size) {
        result.append(color);
    }
    // 한 숫자로 압축되지 않아 4분할할 경우
    else {
        result.append("(");
        // 여기서 x+size/2나 y+size/2가 아니라 x+size처럼 해서 오류났음
        compress(y, x, size/2);
        compress(y, x+size/2, size/2);
        compress(y+size/2, x, size/2);
        compress(y+size/2, x+size/2, size/2);
        result.append(")");
    }

}



int main() {
    cin>>n;

    for(int i=0; i<n; i++) {
        string input;
        cin>>input;
        for(int j=0; j<n; j++) {
            screen[i][j]=input[j];
        }
    }
    compress(0,0,n);
    cout<<result;
    return 0;
}
