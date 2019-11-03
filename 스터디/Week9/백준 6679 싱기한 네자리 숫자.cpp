#include <iostream>
#include <math.h>
using namespace std;

// 각 자릿수별로 더한값
int sum(int num, int s) {
    int ret=0;
    while(num>=1) {
        int x = num%s;
        num = num/s;
        ret += x;
    }
    return ret;
}

int main() {

    for(int num=1000; num<=9999; num++) {

        int s10, s12, s16;
        s10 = sum(num, 10);
        s12 = sum(num, 12);
        s16 = sum(num, 16);
        if(s10==s12&&s10==s16)
            cout<<num<<endl;
    }

    return 0;
}
