#include <bits/stdc++.h>
using namespace std;

string lower(string a){
    string ret;
    for(auto i : a) ret += tolower(i);
    return ret; 
}

int solution(int cacheSize, vector<string> cities) {
    vector<string> cache;
    int ret = 0;
    
    for(auto city: cities){
        string lo = lower(city);
        auto it = find(cache.begin(), cache.end(), lo);
        
        if(it == cache.end()){
            ret += 5;
            cache.push_back(lo);
            
            if(cacheSize < cache.size()){
                cache.erase(cache.begin());
            }
        } else{
            ret += 1;
            cache.erase(it);
            cache.push_back(lo);            
        }        
    }    
    return ret;
}