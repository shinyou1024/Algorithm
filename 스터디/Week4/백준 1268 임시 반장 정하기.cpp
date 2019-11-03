//1268 : 임시 반장 정하기:성공

#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>

int n;
int captain;
using namespace std;
vector<int> check;
int main(int argc, const char * argv[]) {
   cin>>n;

   vector<vector<int> > student(n, vector<int>(0));
   int record[n][5];


   for(int i=0; i<n; i++) {
       for(int j=0; j<5; j++) {
           cin>>record[i][j];
       }
   }


   for(int i=0; i<5; i++) {
       for(int j=0; j<n; j++) {
           for(int k=0; k<n; k++) {
               if(j!=k&&record[j][i]==record[k][i]) {
                   if(find(student[j].begin(), student[j].end(), k)==student[j].end()) {
                       //cout<<i+1<<"학년"<<j+1<<"번 학생"<<"과"<<k+1<<"번 학생"<<endl;
                       //check.push_back(k);
                       student[j].push_back(k);
                   }
               }

           }

           }

           //check.push_back(record[j][i]);
       }

/*
   for(int i=0; i<n; i++) {
       cout<<i<<"번째원소"<<endl;
       cout<<student[0][i]<<endl;
   }
   */
   /*
   for(int i=0; i<n; i++) {
       cout<<student[i].size()<<endl;
   }
    */
/*
   captain = 0;
   for(int i=1; i<n; i++) {
       if(student[i].size()>student[captain].size())
           captain = i;
   }
   cout<<captain+1;

}
