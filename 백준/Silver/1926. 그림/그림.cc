#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int board[502][502];
bool vis[502][502];
int n, m, picNum = 0, visNum = 0;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) cin >> board[i][j];
    
    queue <pair<int, int>> Q;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (vis[i][j] == 0 && board[i][j] == 1)
            {
                vis[i][j] = 1;
                Q.push({i, j});
                int visNum2 = 1;
                
                while (!Q.empty())
                {
                    pair<int, int> cur = Q.front(); Q.pop();
                    
                    for (int dir = 0; dir < 4; dir++)
                    {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        
                        if (nx < 0 || nx >= n || ny < 0 || ny > m) continue;
                        if (vis[nx][ny] || board[nx][ny] != 1) continue;
                        
                        vis[nx][ny] = 1;
                        visNum2++;
                        Q.push({nx, ny});
                    }
                }
                picNum++;
                visNum = max(visNum, visNum2);
                
            }
        }
    }
    cout << picNum << "\n";
    cout << visNum << "\n";
    
}