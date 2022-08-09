#include <bits/stdc++.h>

using namespace std;

int n;
vector <int> adj[100005];
int p[100005];

void dfs(int cur){
  for(int nxt : adj[cur]){
    if (p[cur] == nxt) continue;
    p[nxt] = cur;
    dfs(nxt);
  }
}

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  int a, b;
  for(int i = 0; i < n-1; i++){
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  
  dfs(1);
  for(int i = 2; i <= n; i++) cout << p[i] << '\n';
    
}
