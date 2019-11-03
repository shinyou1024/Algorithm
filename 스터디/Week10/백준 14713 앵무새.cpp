/*
 오답노트
 1. 각 단어마다 공백이 있기 때문에 배열 크기를 더 크게 해야 함
 2. string의 length()는 unsigned int 형으로 반환됨
 => int size를 하나 만들고 저장해서 사용하자
 3. 문제를 잘못 이해함!
    => cseteram은 앵무새가 말하는 모든 문장을 받아적는다
 */

#include <iostream>
#include <string>
#include <string.h>
using namespace std;
int n;
char sentence[102][33333];
int idx[102]; // 각 앵무새 인덱스
string sample;

void isPossible() {
    int idx_s = 0;
    int cnt=0;
    int len = sample.length();
    while (idx_s < len) {

        cnt = 0; // 일치하지 않는 경우를 카운팅 (n마리의 새를 조사했는데 모두 일치하지 않으면 불가능한 것)
        char target = sample[idx_s]; // 찾아야 할 char
        int tem = idx_s; // 루프에서 사용할 임시 인덱스

        for (int j = 1; j <= n; j++) {
            int idx_w = idx[j]; // j번째 앵무새의 현재 인덱스
            while (true) {
                // 공백이면 일치하는 것으로 판정된 것
                if (target == ' ') {
                    idx_s = tem + 1;
                    idx[j] = idx_w+1;
                    break;
                }
                // 일치하지 않으면 cnt를 올려줌
                if (sentence[j][idx_w] != target) {
                    cnt++;
                    if (cnt == n) {
                        cout << "Impossible";
                        return;
                    }
                    break;
                }
                // 일치했을 경우 : 샘플의 다음 char와 j번째 앵무새의 그 다음 char
                tem++;
                // 이때, 마지막 인덱스를 넘어간다면 다 찾은 것
                if (tem >= len) {
                    cout << "Possible";
                    return;
                }
                idx_w++;
                target = sample[tem];
            }
            // for loop 벗어나기 위해
            if (target == ' ')
                break;

        }

    }

}


int main() {
    memset(idx, 0, sizeof(idx));
    cin >> n;

    for (int i = 0; i <= n; i++) {
       // cout << i << endl;
        cin.getline(sentence[i], 3333333);

    }

    getline(cin, sample);
    isPossible();


    return 0;
}
