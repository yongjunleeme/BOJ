#include <bits/stdc++.h>
using namespace std;

const int MX = 202;
int board[MX][MX];
int dist[32][MX][MX];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int kdx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int kdy[8] = {1, -1, 2, -2, 2, -2, 1, -1};
queue<tuple<int, int, int>> Q;
int x, y, k;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> k >> y >> x;
    
    for (int i = 0; i < x; i++)
        for (int j = 0; j < y; j++)
            cin >> board[i][j];
            
    Q.push({0, 0, 0});
    dist[0][0][0] = 1;
    
    while (!Q.empty()) {
        int vk, vx, vy;
        tie(vk, vx, vy) = Q.front(); Q.pop();
        if (vk < k) {
            for (int dir = 0; dir < 8; dir++) {
                int nx = vx + kdx[dir];
                int ny = vy + kdy[dir];
                
                if (nx < 0 || nx >= x || ny < 0 || ny >= y) continue;
                if (board[nx][ny]) continue;
                if (dist[vk + 1][nx][ny]) continue;
                
                dist[vk + 1][nx][ny] = dist[vk][vx][vy] + 1;
                Q.push({vk + 1, nx, ny});
            }
        }
        
        for (int dir = 0; dir < 4; dir++) {
            int nx = vx + dx[dir];
            int ny = vy + dy[dir];
            
            if (nx < 0 || nx >= x || ny < 0 || ny >= y) continue;
            if (board[nx][ny]) continue;
            if (dist[vk][nx][ny]) continue;
            dist[vk][nx][ny] = dist[vk][vx][vy] + 1;
            Q.push({vk, nx, ny});
        }
    }
    
    int ans = 0x7f7f7f7f;
    for (int i = 0; i < k + 1; i++) 
        if (dist[i][x - 1][y - 1]) ans = min(ans, dist[i][x - 1][y - 1]);
    if (ans != 0x7f7f7f7f) cout << ans - 1;
    else cout << -1;
}