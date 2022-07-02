#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m, cnt = 0;
const int MX = 302;
int vis[MX][MX];
int board[MX][MX];
queue <pair<int, int>> Q;
queue <pair<int, int>> Q2;
bool escape = false;


bool OOB(int a, int b){
  return a < 0 || a >= n || b < 0 || b >= m;
}


int main(void){
  ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) cin >> board[i][j];
        
    while(!escape){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == 0) continue;
                for(int dir = 0; dir < 4; dir++){
                    int nx = i + dx[dir];
                    int ny = j + dy[dir];
                    if(OOB(nx, ny)) continue;
                    if(board[nx][ny] == 0) Q.push({i, j});
                }
            }
        }
        
        while(!Q.empty()){
            auto cur = Q.front(); Q.pop();
            if(board[cur.X][cur.Y] != 0) board[cur.X][cur.Y]--;
        }
        
        cnt++;
        int num = 0;
        bool flag = false;

        for(int i = 0; i < n; i++){
            for(int j = 0 ; j < m; j++){
                if(board[i][j] > 0) flag = true;
                if(board[i][j] == 0 || vis[i][j]) continue;
                num++;
                Q2.push({i, j});
                while(!Q2.empty()){
                    auto cur = Q2.front(); Q2.pop();
                    for(int dir = 0; dir < 4; dir++){
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if(OOB(nx, ny) || vis[nx][ny] || board[nx][ny] == 0) continue;
                        vis[nx][ny] = 1;
                        Q2.push({nx, ny});
                    }
                }
                if(num > 1){
                    escape = true;
                    break;
                }
            }
        }
        if(!flag) {
            cout << 0 << "\n";
            return 0;
        }
        for(int i = 0; i < n; i++) fill(vis[i], vis[i] + m, 0);
        
    }
    cout << cnt << "\n";
}
