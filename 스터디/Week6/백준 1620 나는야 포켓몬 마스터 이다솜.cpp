#include <stdio.h>
#include <map>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#define SIZE 100001
using namespace std;

int n, m;

vector<string> input; // 처음에 이름을 입력받는 벡터
vector<pair<string, int> > book(SIZE); // 사전순으로정렬된도감
vector<string> query; // 찾고싶은애들



// 이진검색 함수
void b_search(int x) {
    int low=0;
    int high=n-1;
    while(low<=high) {
        int mid = (low+high)/2;
        // 찾았으면
        if(book[mid].first==query[x]) {
            // 개행문자는 endl보다 \n이 빠름
            cout<<book[mid].second<<"\n";
            break;
        }
        // 찾을 요소가 미드의 요소보다 클 경우 low값조정
        else if(book[mid].first<query[x])
            low = mid+1;
        else
            high = mid-1;
    }
}

void search(int x) {
    // 입력이 문자면
    if(query[x][0]<'0' || query[x][0]>'9') {
        b_search(x);
    }
    // 입력이 숫자면
    else {
        int idx=0;
        for(int j=0; j<query[x].length(); j++) {

            //cout<<"원래 idx"<<idx<<endl;
            // ASCII 테이블에서 '0'은 48이고 '1'부터 '9'까지 49~57임.
            idx+=query[x][j] - '0';

            //cout<<"idx-'0':"<<idx<<endl;
            // 자릿수 맞추기
            idx*= 10;
            //cout<<"idx*10:"<<idx<<endl;


        }
        // 자릿수맞추기위해10곱했던것풀어주기
        idx /=10;
        //cout<<"idx/10:"<<idx<<endl;
         cout << input[idx] << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);

    cin.tie(0);
    cin>>n>>m;
    book.resize(n);
    input.resize(n+1);
    // 도감입력받기
    for(int i=1; i<=n; i++) {
        cin>>input[i];
    }
    for(int i=0; i<n; i++) {
        book[i].first = input[i+1];
        book[i].second = i+1;
    }
    //
    for(int i=0; i<m; i++) {
        string q;
        cin>>q;
        query.push_back(q);
    }
    // 도감을 사전순으로 정렬
    sort(book.begin(), book.end());

    for(int i=0; i<m; i++) {
        search(i);
    }
    return 0;
}
