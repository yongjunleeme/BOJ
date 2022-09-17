#include <bits/stdc++.h>
using namespace std;
string alpha[5] = {"A", "E", "I", "O", "U"};
vector <string> v;

void dfs(int a, string s){    
    if(a == s.size()){
        v.push_back(s);
        return;
    }
    
    for(int i = 0; i < 5; i++){        
        dfs(a, s + alpha[i]);        
    }   
}


int solution(string word) {
    for(int i = 1; i <= 5; i++)
        dfs(i, "");
    sort(v.begin(), v.end());    
    for(int i = 0; i < v.size(); i++)
        if(v[i] == word) return i+1;
}