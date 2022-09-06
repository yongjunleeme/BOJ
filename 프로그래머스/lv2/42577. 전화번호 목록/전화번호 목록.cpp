#include <bits/stdc++.h>
using namespace std;

int mx = 20;
bool solution(vector<string> phone_book) {
    bool answer = true;
    
    unordered_map<string, int> m;    
    
    for(int i = 0 ; i < phone_book.size(); i++){        
        m[phone_book[i]]++;
    }
    
    for(int i = 0 ; i < phone_book.size(); i++){
        string tmp;
        for(int j = 0; j < phone_book[i].size(); j++){
            tmp += phone_book[i][j];            
            if(m.find(tmp) != m.end()) m[phone_book[i]]++;
        }        
    }
    for(auto i: m) if(i.second > 2) return false;
        
    return true;
}