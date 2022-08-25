#include <bits/stdc++.h>

using namespace std;


int solution(vector<int> scoville, int K) {
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());    
    
    int cnt = 0;    
    while(pq.size() > 1 && pq.top() < K){
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        int c = a + b * 2;
        pq.push(c);
        cnt++;        
    }
    if(pq.top() < K) return -1;
    return cnt;
}
