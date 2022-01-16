#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
string board[12];
int vis[14][8];
bool flag;
int ans;

void bfs(int x, int y){
  char color = board[x][y];
  queue<pair<int, int>> q;
  vector<pair<int, int>> tmp;
  
  vis[x][y] = 1;
  q.push({x, y});
  tmp.push_back({x, y});
  while(!q.empty()){
    auto cur = q.front(); q.pop();
      
    for(int i = 0; i < 4; i++){
      int nx = cur.X + dx[i];
      int ny = cur.Y + dy[i];
      if(nx < 0 || nx >= 12 || ny < 0 || ny >= 6) continue;
      if(vis[nx][ny] || board[nx][ny] == '.' || board[nx][ny] != color) continue;
        
      vis[nx][ny] = 1;
      q.push({nx, ny});
      tmp.push_back({nx, ny});
    }
  }
  
  if(tmp.size() >= 4){
    flag = true;
    for(auto c: tmp) board[c.X][c.Y] = '.';
  }
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  for(int i = 0; i < 12; i++) cin >> board[i];
  
  do{
    flag = false;
    for(int i = 0; i < 6; i++){
      for(int j = 10; j >= 0; j--){
        int tmp = j;
        
        while(tmp < 11 && board[tmp+1][i] == '.'){
          swap(board[tmp][i], board[tmp+1][i]);
          ++tmp;
        }
      }
    }
    for(int i = 0; i < 12; i++)
      for(int j = 0; j < 6; j++)
        if(!vis[i][j] && board[i][j] != '.') bfs(i, j);
    
    if(flag) ++ans;
    for(int i = 0; i < 12; i++)
      for(int j = 0; j < 6; j++) vis[i][j] = false;
  }while(flag);
    
  cout << ans;
}
