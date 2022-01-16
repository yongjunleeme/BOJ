#include <bits/stdc++.h>
using namespace std;

// 시간복잡도 개선을 위해 검은색, 흰색 분리
// r+c가 짝수면 0, 홀수면 1

vector<pair<int, int>> board[2][20]; // \방향 칸을 저장
bool used[2][20];
int ans[2];
int n;

void func(int idx, int cnt, int color){
  if(idx == 2*n){
    ans[color] = max(ans[color], cnt);
    return;
  }
  
  for(auto v: board[color][idx]){
    int x, y;
    tie(x, y) = v;
    if(used[color][x+y]) continue;
    used[color][x+y] = 1;
    func(idx+1, cnt+1, color);
    used[color][x+y] = 0;
  }
  func(idx+1, cnt, color);
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      int a;
      cin >> a;
      if(a) board[(i+j+1) %2][n+i-j-1].push_back({i, j});
    }
  }
  func(0,0,0);
  func(0,0,1);
  cout << ans[0] + ans[1];
}
