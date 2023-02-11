#include <bits/stdc++.h>

using namespace std;

unordered_map <char, int> m;
vector <int> ans;

vector<int> solution(string s) {
    for(int i = 0; i < s.size(); i++){
        if (m.find(s[i]) != m.end()){
            ans.push_back(i - m[s[i]]);
            m[s[i]] = i;
        } else{
            ans.push_back(-1);
            m[s[i]] = i;
        }
    }
    return ans;       
    
}