#include <bits/stdc++.h>
using namespace std;

int n, m, u, v;
int a, b;
vector<int> adj[1005];
bool vis[1005] = {false};

// 비재귀
void dfs1(){
  stack<int> s;
  s.push(v);
  while(!s.empty()){
    int cur = s.top(); s.pop();
    if(vis[cur]) continue;
    vis[cur] = true;
    cout << cur << ' ';
    
    for(int i = 0; i < adj[cur].size(); i++){
      // 스택 특성상 정점을 역순으로 넣어야 함
      int nxt = adj[cur][adj[cur].size() - 1 - i];
      if(vis[nxt]) continue;
      s.push(nxt);
    }
  }
}

// 재귀
void dfs2(int cur){
  vis[cur] = true;
  cout << cur << ' ';
  for(auto nxt: adj[cur]){
    vis[nxt] = true;
    dfs2(nxt);
  }
}

void bfs(){
  queue <int> q;
  q.push(v);
  vis[v] = true;
  
  while(!q.empty()){
    int cur = q.front(); q.pop();
    cout << cur << ' ';
    
    for(int nxt : adj[cur]){
      if(vis[nxt]) continue;
      q.push(nxt);
      vis[nxt] = true;
    }
  }
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> v;
  
  while(m--){
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  
  for(int i = 1; i <= n; i++)
    sort(adj[i].begin(), adj[i].end());
  
  dfs1(); // dfs2(v);
  cout << '\n';
  fill(vis+1, vis+1+n, false);
  bfs();
}
