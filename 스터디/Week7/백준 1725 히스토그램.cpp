/*
 1 100 1인 경우 고려
 */
/*
#include <iostream>
#include <vector>
using namespace std;
int n;
int height[100001];
int main() {
    cin>>n;
    for(int i=0; i<n; i++) {
        cin>>height[i];
    }

    // 기준에서 하나씩 옆으로 가면서 최대넓이 갱신
    // 기준보다 짧은 게 나오면 break
    // 그러는 와중에 가장 짧은 친구의 높이는 저장해두기
    int min=height[0];
    int area = height[0];
    vector<int> rec;
    for(int i=0; i<n; i++) {
        //cout<<"i:"<<i<<endl;
        for(int j=i; j<n; j++) {
            //cout<<"j:"<<j<<endl;
            // 짧은 게 나오면 스탑
            if(height[i]>height[j]){
                // 최소높이인지 확인하고 맞으면 갱신
                if(height[j]<min)
                    min= height[j];
                break;
            }
            else {
                // 원래 알고 있던 넓이 보다 넓으면 갱신
                if((j-i+1)*height[i]>area) {
                    //cout<<"새 area:"<<(j-i+1)*height[i]<<endl;
                    area=(j-i+1)*height[i];
                }
            }
        }

    }

    // 최소높이 * n한 것과 비교해서 더 큰 것 출력
    if(area>min*n)
        cout<<area;
    else
        cout<<min*n;
}
