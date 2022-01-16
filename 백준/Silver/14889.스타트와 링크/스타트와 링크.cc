// https://cryptosalamander.tistory.com/61

#include <bits/stdc++.h>
using namespace std;

int n;
int board[22][22];
int isused[22];
int ans = 100;

void func(int k, int cnt){
  int a = 0, b = 0;
  vector<int> v1, v2;
  
  if(cnt == n/2){
    for(int i = 0; i < n; i++){
      if(isused[i]) v1.push_back(i);
      else v2.push_back(i);
    }
    for(int i = 0; i < n/2; i++)
      for(int j = 0; j < n/2; j++){
        a += board[v1[i]][v1[j]];
        b += board[v2[i]][v2[j]];
      }
    
    if(abs(a - b) < ans) ans = abs(a - b);
    return;
  }
  
  for(int i = k; i < n; i++){
    if(!isused[i]){
      isused[i] = 1;
      func(i, cnt+1);
      isused[i] = 0;
    }
  }
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++) cin >> board[i][j];
  
  func(0, 0);
  cout << ans;
}
