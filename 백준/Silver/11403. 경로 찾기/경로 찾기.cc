#include <bits/stdc++.h>
using namespace std;

// https://hunidev.tistory.com/43

int n, a;
vector <int> adj[10005];
int vis[10005];
int ans = 0;
int cnt = 0;
stack<int> s;

void dfs(int cur){
  for(int nxt: adj[cur]){
    if(vis[nxt]) continue;
    vis[nxt] = 1;
    dfs(nxt);
  }
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n;
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      cin >> a;
      if(a == 1){
        s.push(i);
        adj[i].push_back(j);
      }
    }
  }
  
  for(int i = 1; i <= n; i++){
    fill(vis, vis+10005, 0);
    dfs(i);
    for(int j = 1; j <= n; j++){
      cout << vis[j] << ' ';
    }
    cout << '\n';
  }

}
