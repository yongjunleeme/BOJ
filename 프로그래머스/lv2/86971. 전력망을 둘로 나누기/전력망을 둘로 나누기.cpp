#include <bits/stdc++.h>
using namespace std;
int mn = 105;
int vis[105];
queue<int> q;
vector <int> adj[105];

int bfs(int x, int y){
    int cnt = 1;
    q.push(x);    
    vis[x] = 1;

    while(!q.empty()){
        int cur = q.front(); q.pop();        
        for(auto nxt: adj[cur]){
            if(vis[nxt] || nxt == y) continue;
            q.push(nxt);
            vis[nxt] = 1;
            cnt++;
        }            
    }   
    
    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    
    for(int i = 0; i < wires.size(); i++){
        int x = wires[i][0];
        int y = wires[i][1];
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    for(int i = 0; i < wires.size(); i++){
        int x = wires[i][0];
        int y = wires[i][1];        
        
        fill(vis, vis+105, 0);
        mn = min(mn, abs(bfs(x, y) - bfs(y, x)));
        
    }
    return mn;            
}