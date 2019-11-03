#include <iostream>
#include <cstring>
#include <string.h>
#define SIZE 500
using namespace std;
string dna;
int memo[SIZE]; // i번째에서 시작하는 KOI서열의 길이
int dp (int idx) {
    int& ret = memo[idx];
    if(ret!=-1)
        return ret;
    for(int i=0; i<n;i++) {

    }

}

int main() {
    cin>>dna;
    memset(memo, -1, sizeof(memo));
    return 0;

}
