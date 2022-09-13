#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    
    vector <int> tmp; 
    vector<int> ans;
    int mx = 0;
    
    for(int i = 0; i < progresses.size(); i++){
        int a = (99 - progresses[i]) / speeds[i] + 1;   
        tmp.push_back(a);
    }
    
    for(int i = 0; i < tmp.size(); i++){
        if(ans.empty() || tmp[i] > mx) ans.push_back(1);
        else ans.back()++;
        
        mx = max(mx, tmp[i]);
    }
    
    
    return ans;
    
}