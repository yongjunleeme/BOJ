#include <bits/stdc++.h>
using namespace std;

const int MX = 102;
int dist[MX][MX][MX];
int board[MX][MX][MX];
int n, m, h;
int dx[6] = {0, 0, 1, -1, 0, 0};
int dy[6] = {1, -1, 0, 0, 0, 0};
int dh[6] = {0, 0, 0, 0, 1, -1};
queue <tuple<int, int, int>> Q;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> n >> h;
    
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                cin >> board[j][k][i];
                if (board[j][k][i] == 1) Q.push({j, k, i});
                if (board[j][k][i] == 0) dist[j][k][i] = -1;
            }
        }
    }
    
    while (!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        int curX, curY, curH;
        tie(curX, curY, curH) = cur;
        
        for (int dir = 0; dir < 6; dir++) {
            int nx = curX + dx[dir];
            int ny = curY + dy[dir];
            int nh = curH + dh[dir];
            
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || nh < 0 || nh >= h) continue;
            if (dist[nx][ny][nh] >= 0) continue;
            dist[nx][ny][nh] = dist[curX][curY][curH] + 1;
            
            Q.push({nx, ny, nh});
        }
    }
    int result = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                result = max(result, dist[j][k][i]);
                if (dist[j][k][i] == -1) {
                    cout << -1;
                    return 0;
                }
            }
        }
    }
    cout << result;
}