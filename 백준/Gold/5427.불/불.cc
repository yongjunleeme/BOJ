#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
const int MX = 1002;
int dist1[MX][MX];
int dist2[MX][MX];
string board[MX];
int t, n, m;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t; 
    while (t--) {
        queue <pair<int, int>>Q1;
        queue <pair<int, int>>Q2;
        
        
        cin >> m >> n;
        for (int i = 0; i < n; i++) {
            fill(dist1[i], dist1[i] + m, -1);
            fill(dist2[i], dist2[i] + m, -1);
        }
        
        for (int i = 0; i < n; i++) {
            cin >> board[i];
            for (int j = 0; j < m; j++) {
                if (board[i][j] == '*') {
                    Q1.push({i, j});
                    dist1[i][j] = 0;
                }
                else if (board[i][j] == '@') {
                    Q2.push({i, j});
                    dist2[i][j] = 0;
                }
            }
        }
        
        while (!Q1.empty()) {
            auto cur = Q1.front(); Q1.pop();
            
            for (int dir = 0; dir < 4; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (dist1[nx][ny] >= 0 || board[nx][ny] == '#') continue;
                
                dist1[nx][ny] = dist1[cur.X][cur.Y] + 1;
                Q1.push({nx, ny});
            }
        }
        
        bool escape = false;
        while (!Q2.empty() && !escape) {
            auto cur = Q2.front(); Q2.pop();
            
            for (int dir = 0; dir < 4; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                    cout << dist2[cur.X][cur.Y] + 1 << "\n";
                    escape = true;
                    break;
                    
                }
                if (dist2[nx][ny] >= 0 || board[nx][ny] == '#') continue;
                if (dist1[nx][ny] != -1 && dist1[nx][ny] <= dist2[cur.X][cur.Y] + 1) continue;
                
                dist2[nx][ny] = dist2[cur.X][cur.Y] + 1;
                Q2.push({nx, ny});
            }
        }
        if (!escape) cout << "IMPOSSIBLE" << "\n";
    }

}