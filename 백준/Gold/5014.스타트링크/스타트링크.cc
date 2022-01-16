#include <bits/stdc++.h>
using namespace std;

int f, s, g, u, d;
int dist[1000002];
queue <int> Q;

int main(void) {
    cin >> f >> s >> g >> u >> d;
    
    fill(dist, dist + 1 + f, -1);
    dist[s] = 0;
    Q.push(s);
    
    while (!Q.empty()) {
        int cur = Q.front(); Q.pop();
        
        for (int nxt : {cur + u, cur - d}) {
            if (nxt <= 0 || nxt > f) continue;
            if (dist[nxt] >= 0) continue;
            dist[nxt] = dist[cur] + 1;
            
            Q.push(nxt);
        }
    }
    
    if (dist[g] == -1) cout << "use the stairs";
    else cout << dist[g];
}