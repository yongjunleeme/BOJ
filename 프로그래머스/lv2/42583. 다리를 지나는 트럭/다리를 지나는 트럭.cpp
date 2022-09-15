#include <bits/stdc++.h>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int idx = 0;
    int cnt = 0;
    queue <int> q;
    int w = 0;
    
    while(1){
        
        cnt++;
        
        if(q.size() == bridge_length){
            
            w -= q.front();
            q.pop();
        }
        
        if(w + truck_weights[idx] <= weight){
            
            if(idx == truck_weights.size() - 1){
                cnt += bridge_length;
                break;
            }
            
            q.push(truck_weights[idx]);
            w += truck_weights[idx];
            idx++;
        } else {
                       
            
            q.push(0);            
        }
    }
    return cnt;
   
}