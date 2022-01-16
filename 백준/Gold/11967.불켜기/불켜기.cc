// 종이의 개수, N-Queen, 부분수열 복습

#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int n, m, cnt = 0;
const int MX = 102;
int board[MX][MX];
int vis[MX][MX];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
vector <pair<int, int>> V[MX][MX];

bool OOB(int a, int b){
  return a < 1 or a > n or b < 1 or b > n;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  int x, y, a, b;
  
  for (int i = 0; i < m; i++) {
    cin >> x >> y >> a >> b;
    V[x][y].push_back({a, b});
  }
  
  queue <pair<int, int>> Q;
  board[1][1] = 1;
  vis[1][1] = 1;
  Q.push({1, 1});
  
  while (!Q.empty()) {
    auto cur = Q.front(); Q.pop();
    vis[cur.X][cur.Y] = 1;
    
    for (int k = 0; k < V[cur.X][cur.Y].size(); k++) {
      int aa = V[cur.X][cur.Y][k].X;
      int bb = V[cur.X][cur.Y][k].Y;
      
      if(vis[aa][bb]) continue;
      for(int dir = 0; dir < 4; dir++){
        int nx = aa + dx[dir];
        int ny = bb + dy[dir];
        if(OOB(nx, ny)) continue;
        if(vis[nx][ny]) {
          vis[aa][bb] = 1;
          Q.push({aa, bb});
        }
      }
      board[aa][bb] = 1;
    }
    
    for (int dir = 0; dir < 4; dir++){
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      
      if(OOB(nx,ny) || vis[nx][ny] || !board[nx][ny]) continue;
      vis[nx][ny] = 1;
      Q.push({nx, ny});
    }
  }
  
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) if (board[i][j]) cnt++;
    
  cout << cnt;
}
