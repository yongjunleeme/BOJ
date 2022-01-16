#include <bits/stdc++.h>
using namespace std;

bool arr[25];
string board[5];
int ans;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for(int i = 0; i < 5; i++) cin >> board[i];
  fill(arr+7, arr+25, 1);
  
  do{
    queue<pair<int, int>> q;
    int cnt1 = 0, cnt2 = 0;
    bool vis[5][5] = {}, isPossible[5][5] = {};
    
    for(int i = 0; i < 25; i++)
      if(!arr[i]){
        int x = i/5;
        int y = i%5;
        isPossible[x][y] = 1;
        
        if(q.empty()){
          q.push({x, y});
          vis[x][y] = 1;
        }
      }
    
    while(!q.empty()){
      int x, y;
      tie(x, y) = q.front(); q.pop();
      cnt2++;
      cnt1 += board[x][y] == 'S';
      
      for(int k = 0; k < 4; k++){
        int nx = x + dx[k];
        int ny = y + dy[k];
        
        if(nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
        if(vis[nx][ny] || !isPossible[nx][ny]) continue;
        q.push({nx, ny});
        vis[nx][ny] = 1;
      }
    }
    ans += (cnt1 >= 4 && cnt2 >= 7);
  }while(next_permutation(arr, arr+25));
  cout << ans;
}
