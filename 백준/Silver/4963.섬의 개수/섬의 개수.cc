#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int dx[8] = {1, 0, -1, 0, -1, -1, 1, 1};
int dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};
int board[55][55];
int vis[55][55];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  while(1){
    int a, b;
    stack<pair<int, int>> s;
    vector<pair<int, int>> v;
    int cnt = 0;
    cin >> a >> b;
    if(a == 0 && b == 0) break;
    for(int i = 0; i < b; i++){
      for(int j = 0; j < a; j++){
        board[i][j] = 0;
        vis[i][j] = 0;
      }
    }
    for(int i = 0; i < b; i++){
      for(int j = 0; j < a; j++){
        cin >> board[i][j];
        if(board[i][j] == 1) v.push_back({i, j});
      }
    }
    
    for(int i = 0; i < v.size(); i++){
      int x = v[i].X;
      int y = v[i].Y;
      if(vis[x][y]) continue;
      vis[x][y] = 1;
      cnt++;
      s.push({x,y});
      while(!s.empty()){
        auto cur = s.top(); s.pop();
        vis[cur.X][cur.Y] = 1;
        
        // 대각선도 가야한다. 한 번에 컴파일하는 문제였다면 틀렸을 것이다.
        for(int dir = 0; dir < 8; dir++){
          int nx = cur.X + dx[dir];
          int ny = cur.Y + dy[dir];
          if(nx < 0 || nx >= b || ny < 0 || ny >= a) continue;
          if(board[nx][ny] == 0 || vis[nx][ny]) continue;
          vis[nx][ny] = 1;
          s.push({nx, ny});
        }
      }
    }
    cout << cnt << '\n';
  }
}
