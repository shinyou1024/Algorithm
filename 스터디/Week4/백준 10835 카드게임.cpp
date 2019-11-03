// 카드게임:성공

#include <stdio.h>
#include <iostream>
#include <algorithm>

int left[2001];
int right[2001];
int score[2001][2001];

int n;
int card;


int game(int l, int r) {
    // 카드 다 쓴 경우
    if(l==n||r==n)
        return 0;
    // 이미 계산한 거
    if(score[l][r]!=-1)
        return score[l][r];
    // 오른쪽의 숫자가 더 크면
    // 카드 개수가 더 적은 수준에서 돌린 결과 중 더 높은 점수인 거 저장
    score[l][r]=std::max(game(l+1, r), game(l+1,r+1));
    // 오른쪽의 숫자가 더 작으면
    // 이 부분!!!
    if(left[l]>right[r])
        score[l][r]=std::max(score[l][r], game(l, r+1)+right[r]);

    return score[l][r];
}
int main(int argc, const char * argv[]) {
    std::cin>>n;
    // score 배열 초기화 : -1로 하는 이유(점수가0인거랑 구분짓기 위해)
    for(int i=0; i<2001; i++) {
        for(int j=0; j<2001; j++)
            score[i][j]=-1;
    }

    // 카드 입력 받기
    for(int i=0; i<n; i++) {
        std::cin>>left[i];
    }
    for(int i=0; i<n; i++) {
        std::cin>>right[i];
    }
    std::cout<<game(0,0);
    return 0;
}
