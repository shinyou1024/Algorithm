#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    string s1;
    string s2;
    cin>>s1;
    cin>>s2;
    // 일단 서로 갖고 있지 않은 문자 빼기
    for(int i=0; i<s1.size(); i++) {
        int location = s2.find(s1.at(i));
        if (location==string::npos) {
            s1.erase(i, 1);
        }
    }
    queue<string> q;
    for(int i=0; i<n; i++) {
        string target = s1.at(i);
        q.push(target);
        if(s2.find(target)!=string::npos) {

        }

    }

    return 0;
}
