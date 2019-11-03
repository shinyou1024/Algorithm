// 수열:성공
#include <stdio.h>
#include <iostream>
using namespace std;

int n; // 날짜 수
int k; // 합산할 주기
 */
/*
 // 인덱스 0부터 n-k-1까지 k일마다의 온도합 구하는 함수 : 시간초과
void addTemp(int arr1[], int arr2[], int k) {
    for(int i=0; i<n-k; i++) {
        for(int j=0; j<k; j++) {
            //cout<<arr1[i+j]<<"더하기!"<<endl;
            arr2[i] += arr1[i+j];
        }
            //arr2[i] = arr1[j];
        //cout<<i<<"번째 합은"<<arr2[i]<<endl;
    }

}
*/
/*
void addTemp(int temp[], int sum[], int k) {
    //sum[0]부터 구하기
    for(int i=0; i<k; i++) {
        sum[0] +=temp[i];
    }
    // k일 동안의 온도합을 한 세트라 하면
    //   각 세트의 합은 그 "전 세트의 합 - 전날기온 + k+i-1일의 기온"임
    //    k=3일 때, 1세트는 1,2,3일의 기온 합. 2세트는 2,3,4의 합이므로 1세트에서 1일차를 빼고 4일차를 한 것과 동일.

    for(int i=1; i<n-k+1; i++) {
        sum[i] = sum[i-1]-temp[i-1]+temp[k+i-1];
        //cout<<sum[i-1]<<"빼기"<<temp[i-1]<<"더하기"<<temp[k+i-1]<<"는"<<sum[i]<<endl;
    }
}
int main(int argc, const char * argv[]) {
    cin>>n>>k;
    int temp[n]; // 입력된 n일간의 기온
    int sum[n-k+1]; //k일마다 기온을 더한 것

    // sum초기화
    for(int i=0; i<n-k+1; i++) {
        sum[i]=0;
    }

    for(int i=0; i<n; i++) {
        cin>>temp[i];
    }

    addTemp(temp, sum, k);



    // 최댓값 찾기
    int max = sum[0];
    for(int i=0; i<n-k+1; i++) {
       if(max<sum[i])
           max = sum[i];
    }
    cout<<max;

}
