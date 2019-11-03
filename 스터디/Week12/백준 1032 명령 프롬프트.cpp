#include <iostream>
#include <string>
using namespace std;
int n;
string ans;

int main() {
    cin >> n;
    cin >> ans;
    for(int i=1; i<n; i++) {
        string tmp;
        cin >> tmp;

        for(int j = 0; j<ans.length(); j++) {
            if(ans[j]!=tmp[j])
                ans[j]='?';
        }
    }
    /*
     string str[52]; // 각 파일명을 저장
    for(int i=0; i<str[0].length(); i++) {
        char c = str[0][i];
        if(c==NULL)

        bool isPattern = true;
        for(int j=1; j<n; j++) {

            if(c != str[j][i]) {
                isPattern = false;
                break;
            }
        }
        if(isPattern == true) {
            char cstr[1];
            cstr[0] = c;
            string s = cstr;
            ans.append(s);
        }
        else {
            ans.append("?");
        }
    }
     *//*
    cout << ans << endl;
    return 0;
}
