#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dist[2][500001];
int n, k;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cout << fixed;
    cout.precision(20);
    
    cin >> n >> k;
    fill(dist[0], dist[0] + 500001, -1);
    fill(dist[1], dist[1] + 500001, -1);
    dist[0][n] = 0;
    queue<pair<int, int>>Q;
    Q.push({0, n});
    while (!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        for (auto nxt : {cur.Y - 1, cur.Y + 1, cur.Y * 2}) {
            if (nxt < 0 || nxt > 500000) continue;
            if (dist[1 - cur.X][nxt] != -1) continue;
            dist[1 - cur.X][nxt] = dist[cur.X][cur.Y] + 1;
            Q.push({1 - cur.X, nxt});
        }
    }
    // 홀수 - 4 6 10
    // 짝수 - 3 5 8   5 7 12   9 11 20
    // 홀수 - 5--> 4 6 10
        
    int ans = 0x7f7f7f7;
    int tt = 0;
    while (k <= 500000) {
        if (dist[tt % 2][k] != -1 && dist[tt % 2][k] <= tt) ans = min(ans, tt);
        tt++;
        k += tt;
    }
    if (ans == 0x7f7f7f7) ans = -1;
    cout << ans;
}