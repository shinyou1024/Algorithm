*
 오답노트
    1. 어느 한 면을 돌릴 때 인접한 면과 함께 자기 자신도 돌아간다
        => 자기 면 안에서 배치 바뀜!!!!
 */
#include <iostream>
#include <string.h>
using namespace std;

struct Side{
    char color[3][3];

    void rotate_clock() {
        char temp1 = color[0][0];
        char temp2 = color[1][0];
        color[0][0]=color[2][0];
        color[1][0]=color[2][1];
        color[2][0]=color[2][2];
        color[2][1]=color[1][2];
        color[2][2]=color[0][2];
        color[1][2]=color[0][1];
        color[0][2]=temp1;
        color[0][1]=temp2;

    }

    void rotate_counter() {
        char temp1 = color[0][0];
        char temp2 = color[0][1];
        color[0][0]=color[0][2];
        color[0][1]=color[1][2];
        color[0][2]=color[2][2];
        color[1][2]=color[2][1];
        color[2][2]=color[2][0];
        color[2][1]=color[1][0];
        color[2][0]=temp1;
        color[1][0]=temp2;

    }

};
int T;
char iColor[6] = { 'w', 'y', 'r', 'o', 'g', 'b' };
Side cube[6];

// cube 초기화
void init() {
    for (int i = 0; i < 6; i++) {
        memset(cube[i].color, iColor[i], sizeof(cube[i].color));
    }
}

// 자기 돌리기

void clock(char side) {
    int temp[3];
    if (side == 'U') {
        cube[0].rotate_clock();
        for (int i = 0; i < 3; i++) {
            temp[i] = cube[2].color[0][i];
        }
        for (int i = 0; i < 3; i++) {
            cube[2].color[0][i] = cube[5].color[0][i];
        }
        for (int i = 0; i < 3; i++) {
            cube[5].color[0][i] = cube[3].color[0][i];
        }
        for (int i = 0; i < 3; i++) {
            cube[3].color[0][i] = cube[4].color[0][i];
        }
        for (int i = 0; i < 3; i++) {
            cube[4].color[0][i] = temp[i];
        }

    }
    if (side == 'D') {
        cube[1].rotate_clock();
        for (int i = 0; i < 3; i++) {
            temp[i] = cube[2].color[2][i];
        }
        for (int i = 0; i < 3; i++) {
            cube[2].color[2][i] = cube[4].color[2][i];
        }
        for (int i = 0; i < 3; i++) {
            cube[4].color[2][i] = cube[3].color[2][i];
        }
        for (int i = 0; i < 3; i++) {
            cube[3].color[2][i] = cube[5].color[2][i];
        }
        for (int i = 0; i < 3; i++) {
            cube[5].color[2][i] = temp[i];
        }
    }
    //
    if (side == 'F') {
        cube[2].rotate_clock();
        for (int i = 0; i < 3; i++) {
            temp[i] = cube[0].color[2][i];
        }
        for (int i = 0; i < 3; i++) {
            cube[0].color[2][i] = cube[4].color[2][i];
        }
        for (int i = 0; i < 3; i++) {
            cube[4].color[2][i] = cube[1].color[2][i];
        }
        for (int i = 0; i < 3; i++) {
            cube[1].color[2][i] = cube[5].color[2][i];
        }
        for (int i = 0; i < 3; i++) {
            cube[5].color[2][i] = temp[i];
        }
    }
    //
    if (side == 'B') {
        cube[3].rotate_clock();
        for (int i = 0; i < 3; i++) {
            temp[i] = cube[0].color[0][i];
        }
        for (int i = 0; i < 3; i++) {
            cube[0].color[0][i] = cube[5].color[0][i];
        }
        for (int i = 0; i < 3; i++) {
            cube[5].color[0][i] = cube[1].color[0][i];
        }
        for (int i = 0; i < 3; i++) {
            cube[1].color[0][i] = cube[4].color[0][i];
        }
        for (int i = 0; i < 3; i++) {
            cube[4].color[0][i] = temp[i];
        }
    }

    if (side == 'L') {

        cube[4].rotate_clock();

        for (int i = 0; i < 3; i++) {
            temp[i] = cube[0].color[i][0];
        }
        for (int i = 0; i < 3; i++) {
            cube[0].color[i][0] = cube[3].color[i][0];
        }
        for (int i = 0; i < 3; i++) {
            cube[3].color[i][0] = cube[1].color[i][0];
        }
        for (int i = 0; i < 3; i++) {
            cube[1].color[i][0] = cube[2].color[i][0];
        }
        for (int i = 0; i < 3; i++) {
            cube[2].color[i][0] = temp[i];
        }
    }
    if (side == 'R') {
        cube[5].rotate_clock();
        for (int i = 0; i < 3; i++) {
            temp[i] = cube[0].color[i][2];
        }
        for (int i = 0; i < 3; i++) {
            cube[0].color[i][2] = cube[2].color[i][2];
        }
        for (int i = 0; i < 3; i++) {
            cube[2].color[i][2] = cube[1].color[i][2];
        }
        for (int i = 0; i < 3; i++) {
            cube[1].color[i][2] = cube[3].color[i][2];
        }
        for (int i = 0; i < 3; i++) {
            cube[3].color[i][2] = temp[i];
        }
    }


}

void counterclock(char side) {
    int temp[3];
    if (side == 'U') {

        cube[0].rotate_counter();

        for (int i = 0; i < 3; i++) {
            temp[i] = cube[2].color[0][i];
        }
        for (int i = 0; i < 3; i++) {
            cube[2].color[0][i] = cube[4].color[0][i];
        }
        for (int i = 0; i < 3; i++) {
            cube[4].color[0][i] = cube[3].color[0][i];
        }
        for (int i = 0; i < 3; i++) {
            cube[3].color[0][i] = cube[5].color[0][i];
        }
        for (int i = 0; i < 3; i++) {
            cube[5].color[0][i] = temp[i];
        }

    }
    if (side == 'D') {
        cube[1].rotate_counter();
        for (int i = 0; i < 3; i++) {
            temp[i] = cube[2].color[2][i];
        }
        for (int i = 0; i < 3; i++) {
            cube[2].color[2][i] = cube[5].color[2][i];
        }
        for (int i = 0; i < 3; i++) {
            cube[5].color[2][i] = cube[3].color[2][i];
        }
        for (int i = 0; i < 3; i++) {
            cube[3].color[2][i] = cube[4].color[2][i];
        }
        for (int i = 0; i < 3; i++) {
            cube[4].color[2][i] = temp[i];
        }
    }

    if (side == 'F') {
        cube[2].rotate_counter();
        for (int i = 0; i < 3; i++) {
            temp[i] = cube[0].color[2][i];
        }
        for (int i = 0; i < 3; i++) {
            cube[0].color[2][i] = cube[5].color[2][i];
        }
        for (int i = 0; i < 3; i++) {
            cube[5].color[2][i] = cube[1].color[2][i];
        }
        for (int i = 0; i < 3; i++) {
            cube[1].color[2][i] = cube[4].color[2][i];
        }
        for (int i = 0; i < 3; i++) {
            cube[4].color[2][i] = temp[i];
        }
    }

    if (side == 'B') {
        cube[3].rotate_counter();
        for (int i = 0; i < 3; i++) {
            temp[i] = cube[0].color[0][i];
        }
        for (int i = 0; i < 3; i++) {
            cube[0].color[0][i] = cube[4].color[0][i];
        }
        for (int i = 0; i < 3; i++) {
            cube[4].color[0][i] = cube[1].color[0][i];
        }
        for (int i = 0; i < 3; i++) {
            cube[1].color[0][i] = cube[5].color[0][i];
        }
        for (int i = 0; i < 3; i++) {
            cube[5].color[0][i] = temp[i];
        }
    }
    //
    if (side == 'L') {

        cube[4].rotate_counter();
        for (int i = 0; i < 3; i++) {
            temp[i] = cube[0].color[i][0];
        }
        for (int i = 0; i < 3; i++) {
            cube[0].color[i][0] = cube[2].color[i][0];
        }
        for (int i = 0; i < 3; i++) {
            cube[2].color[i][0] = cube[1].color[i][0];
        }
        for (int i = 0; i < 3; i++) {
            cube[1].color[i][0] = cube[3].color[i][0];
        }
        for (int i = 0; i < 3; i++) {
            cube[3].color[i][0] = temp[i];
        }
    }
    if (side == 'R') {
        cube[5].rotate_counter();
        for (int i = 0; i < 3; i++) {
            temp[i] = cube[0].color[i][2];
        }
        for (int i = 0; i < 3; i++) {
            cube[0].color[i][2] = cube[3].color[i][2];
        }
        for (int i = 0; i < 3; i++) {
            cube[3].color[i][2] = cube[1].color[i][2];
        }
        for (int i = 0; i < 3; i++) {
            cube[1].color[i][2] = cube[2].color[i][2];
        }
        for (int i = 0; i < 3; i++) {
            cube[2].color[i][2] = temp[i];
        }
    }


}

int main()
{


    cin >> T;
    for (int test_case = 0; test_case < T; test_case++) {
        init();

        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            char which, dir;
            cin >> which >> dir;
            if (dir == '+') {
                clock(which);
            }
            else {
                counterclock(which);
            }

        }

        // 윗면 출력

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << cube[0].color[i][j];
            }
            cout <<endl;
        }



    }
}
