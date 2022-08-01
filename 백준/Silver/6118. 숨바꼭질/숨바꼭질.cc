#include <bits/stdc++.h>
using namespace std;

int n, m, a, b;
vector <int> adj[20005];
int dist[20005];
int mx = 0;

void bfs(){
  queue <int> q;
  q.push(1);
  fill(dist, dist+n+1, -1);
  
  dist[1] = 0;
  while(!q.empty()){
    int cur = q.front(); q.pop();
    
    for(int nxt: adj[cur]){
      if(dist[nxt] >= 0) continue;
      dist[nxt] = dist[cur] + 1;
      mx = max(dist[nxt], mx);
      q.push(nxt);
    }
  }
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n >> m;
  while(m--){
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  
  bfs();
  
  int cnt = 0;
  for(int i = 2; i <= n; i++){
    if(dist[i] == mx) cnt++;
  }
  for(int i = 2; i <= n; i++){
    if(dist[i] == mx){
      cout << i << " " << mx << " " << cnt;
      break;
    }
  }
}
