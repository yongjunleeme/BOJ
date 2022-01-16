#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n;
const int MX = 102;
int board[MX][MX];
int vis[MX][MX];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) cin >> board[i][j];

  vector < int > ans;
  for (int k = 1; k <= 100; k++) {
    queue < pair < int, int >> Q;
    int cnt = 0;
    for (int i = 0; i < n; i++) fill(vis[i], vis[i] + n, 0);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        if (board[i][j] <= k) vis[i][j] = 1;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (board[i][j] > k && vis[i][j] == 0) {
          Q.push({i,j});
          vis[i][j] = 1;
          cnt++;
          while (!Q.empty()) {
            auto cur = Q.front();
            Q.pop();
            for (int dir = 0; dir < 4; dir++) {
              int nx = cur.X + dx[dir];
              int ny = cur.Y + dy[dir];
              if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
              if (vis[nx][ny] == 1) continue;
              vis[nx][ny] = 1;
              Q.push({nx,ny});
            }
          }
        }
      }
    }
    ans.push_back(cnt);
  }
  int result = *max_element(ans.begin(), ans.end());
  if (result == 0) cout << 1;
  else cout << result;
}