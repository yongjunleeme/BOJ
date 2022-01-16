#include <bits/stdc++.h>
using namespace std;

int n, m, x, y, d;
int board[55][55];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int ans = 0;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> x >> y >> d;
  for(int i = 0; i < n; ++i)
    for(int j = 0; j < m; ++j) cin >> board[i][j];
  
  while(1){
    // 청소하지 않은 빈 칸일 경우 청소
    if(!board[x][y]) ++ans;
    board[x][y] = -1; // 청소된 칸이라고 표시
    bool cleaned = false; // 네 방향 중 청소가 된 곳이 있는지
    for(int i = 0; i < 4; i++){
      d = (d+3) % 4; // 왼쪽으로 회전
      if(!board[x+dx[d]][y+dy[d]]){
        x += dx[d];
        y += dy[d];
        cleaned = true;
        break;
      }
    }
    if(cleaned) continue;
    // 뒤가 벽으로 막혀 있으면, 로봇 청소기 종료
    if(board[x-dx[d]][y-dy[d]] == 1) break;
    // 막혀 있지 않을 경우, 후진
    x -= dx[d];
    y -= dy[d];
  }
  
  cout << ans;
}
