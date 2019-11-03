#include <iostream>
#include <string>
#include <vector>
#include <string.h>
#include <stack>
using namespace std;


string reverse(vector<char> arr) {

    int size = arr.size();
    char ret[size];
    int idx = 0;
    for(int i=size-1; i>=0; i--) {
        ret[idx] = arr[i];
    }
    string str = ret;
    return str;
}

int main(int argc, const char * argv[]) {
    char input[121];
    cin.get(input, 121);
    int endex;
    for(int i=0; i<121; i++) {
        if(input[i]==';') {
            endex = i;
            break;
        }
    }

    int cnt = 1;
    for(int i=0; i<endex; i++) {
        if(input[i]==',') {
            cnt++;
        }
    }

    int idx = 0;
    char c = input[0];
    vector<char> type;
    while(c!=' ') {
        type.push_back(input[idx]);
        idx++;
        c = input[idx];
    }

    //int cnt = 0;
    char ch = input[idx+1];
    stack<char> name[100];
    vector<char> addi[100];
    int vdx=0;

    for(int i=endex-1; i>idx; i--) {
        ch = input[i];
        if(ch == ',') {
            vdx++;
        }
        if(ch=='*' || ch=='&') {
            addi[vdx].push_back(ch);
        }

        if(ch==']') {
            addi[vdx].push_back('[');
            addi[vdx].push_back(']');
        }
        if(ch=='[')
            continue;
        //알파벳일 경우
        else {
            name[vdx].push(ch);
        }
    }

    for(int i=cnt-1; i>=0; i--) {
        for(int j=0; j<type.size(); j++)
            cout<<type[j];
        for(int j=0; j<addi[i].size(); j++)
            cout<<addi[i][j];

        if(i==cnt-1)
            cout<<" ";

        for(int j=0; j<name[i].size(); j++) {
            cout<<name[i].top();
            name[i].pop();
        }

        cout<<";"<<endl;
    }
    /*

    string output = type;


    char ch = s.at(idx+1);
    vector<char> name;

    for(int i=size-1; i>idx; i--) {
        ch = s.at(i);
        if(ch==' ') {
            string namae = reverse(name);
            output.append(" ");
            output.append(namae);
            cout<<output<<endl;
            output = type;
            continue;
        }
        if(ch=='*') {
            output.append("*");
        }
        if(ch=='&')
           output.append("&");
        if(ch==']') {
            output.append("[]");
            i--;
        }
        //알파벳일 경우
        else {
            name.push_back(ch);
        }



    }


    cout <<output;
    */
    return 0;
}
