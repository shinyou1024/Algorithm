#include <iostream>

using namespace std;
int n;
int map[102][102];
int main() {
//freopen("input.txt", "r", stdin);
 for (int tc = 1; tc <= 10; tc++) {
  int ans = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) {
   for (int j = 1; j <= n; j++)
    cin >> map[i][j];
  }

  //cout << "입력완료" << endl;

  for (int c = 1; c <= n; c++) {
  	int check = 0;
  	for(int r = 1; r<=n; r++) {
  		if(map[r][c]==0)
  			continue;

  		else if(check == 1 && map[r][c]==2) {
  			ans ++;
  			check = 0;
		  }
		  else if(map[r][c]==1)
  			check = 1;
	  }
  }
  cout << "#" << tc << " " << ans<<"\n";
 }
 return 0;
}
