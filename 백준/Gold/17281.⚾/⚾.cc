// https://sejinik.tistory.com/209

#include <bits/stdc++.h>
using namespace std;

int n;
int ans = 0;
int board[10][55]; // [타자][n]

int arr[1500];
int order[9] = {3,0,1,2,4,5,6,7,8};
int norder[9];


/*
 2
 4 2 1 0 0 1 1 0 0
 0 0 0 0 0 0 0 0 0
 */
int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < 9; j++)
      cin >> board[j][i];
  
  do{
    for(int i = 0; i < 9; i++) norder[order[i]] = i;
    // noder[3] = 0, norder[0] = 1, norder[1] = 2, norder[2] = 3 ...
    
    int cnt = 0;
    int pos = 0;
    for(int i = 0; i < n; i++){
      int out = 0;
      int prev = pos;
      
      while(out != 3){
        int num = board[norder[pos%9]][i];
        // num = board[1][0], num = board[2][0], num = board[3][0], num = board[0][0] ...
        if(num == 0) out += 1;
        arr[pos++] = num;
        // arr[0] = 3. arr[1] = 2, arr[2] = 1, arr[3] = 4 ...
        // pos는 3아웃된 수로 증가
      }
      for(int j = prev; j < pos; j++){
        // prev = 0, pos = 3아웃된 수
        // 0~3
        if(!arr[j]) continue;
        for(int k = j+1; k < pos; k++)
          // 1~3
          // arr[0] = 4+2, arr[1] = 2+1, arr[2] = 1+0...
          // arr[1] = 2+1, arr[2] = ..

          arr[j] += arr[k];
      }
    }
    for(int j = 0; j < pos; j++) if(arr[j] >= 4) cnt+= 1;
    ans = max(ans, cnt);
  }while(next_permutation(order+1, order+9));
  cout << ans;
}
