#include <bits/stdc++.h>
using namespace std;

map<string, int> freq[11];

vector<string> solution(vector<string> orders, vector<int> course) {    

    for(auto order : orders){
        sort(order.begin(), order.end());
        
        for(int i = 0; i < (1 << order.size()); i++){
            string menu;            
            
            for(int j = 0; j < order.size(); j++){
                if(i & (1 << j)) menu += order[j];
            }
            
            freq[menu.size()][menu]++;            
        }
    }
    
    vector<string> ans;
    for(auto i : course){
        
        int mxfreq = 0;        
        for(auto p : freq[i])
            mxfreq = max(mxfreq, p.second);
        
        if(mxfreq < 2) continue;
        
        for(auto p : freq[i])
            if(p.second == mxfreq) ans.push_back(p.first);        
    }
    
    sort(ans.begin(), ans.end());
    return ans;
    
}