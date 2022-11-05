#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> prices) {    
    vector<int> answer;
    for(int i = 0; i < prices.size(); i++){
        int tmp = prices[i];
        int cnt = 0;
        
        for(int j = i; j < prices.size(); j++){
            if(i == j) continue;
            if(tmp <= prices[j]) cnt++;
            else {
                cnt++;
                break;
            }
        }
        answer.push_back(cnt);
    }
    
    
    
    return answer;
}