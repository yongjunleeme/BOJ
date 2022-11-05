#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> priorities, int location) {
    priority_queue <int> pq;
    queue <pair<int, int>> q;
    
    for(int i = 0; i < priorities.size(); i++){
        pq.push(priorities[i]);
        q.push({priorities[i], i});
    }
    int cnt = 0;
    
    while(!q.empty()){
        if(q.front().first == pq.top()){
            cnt++;            
            if(q.front().second == location) return cnt;
            q.pop(); pq.pop();            
        } else {
            auto a = q.front(); q.pop();
            q.push({a.first, a.second});
            
        }
    }
    
}