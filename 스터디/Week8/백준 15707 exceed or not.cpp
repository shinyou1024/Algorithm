#include <iostream>
#include <math.h>
using namespace std;
unsigned long long int a, b, r;
float mul; // a*b/10^20할 거
unsigned long long int mul2;
float r2; // r/10^20할 거

int main() {
    cin>>a>>b>>r;
    if(a>=pow(10,20)&&b>) {
        mul = a*b/pow(10,10);
        cout<<mul<<endl;
        r2 = r/pow(10,10);
        cout<<r2;
        if(mul>r2)
            cout<<"overflow";
        //else
            //cout<<mul*pow(10,10);
    }
    else {
        mul2 = a*b;
        if(mul2>r)
            cout<<"overflow";
        else
            cout<<mul2;
    }


    return 0;
}
