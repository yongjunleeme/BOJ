#include <bits/stdc++.h>
using namespace std;

int n, m, a, b;
vector <int> adj[10005];
int vis[10005];
int ans = 0;
int cnt = 0;
int mx = 0;

void dfs(int cur){
  vis[cur] = 1;
  cnt++;
  for(int nxt: adj[cur]){
    if(vis[nxt]) continue;
    dfs(nxt);
  }
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n >> m;
  while(m--){
    cin >> a >> b;
    adj[b].push_back(a);
  }
  
  vector <pair<int, int>> ans;
  
  for(int i = 1; i <= n; i++){
    dfs(i);
    ans.push_back({i, cnt});
    mx = max(cnt, mx);
    cnt = 0;
    fill(vis, vis+10005, 0);
  }
  sort(ans.begin(), ans.end());
  for(auto nxt: ans) if(nxt.second == mx) cout << nxt.first << ' ';
}
