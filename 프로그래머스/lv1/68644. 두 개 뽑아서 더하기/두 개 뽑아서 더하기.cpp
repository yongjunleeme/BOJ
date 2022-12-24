#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> numbers) {
    unordered_set <int> s;
    
    for(int i = 0; i < numbers.size(); i++){
        for(int j = 0; j < numbers.size(); j++){
            if(i == j) continue;
            s.insert(numbers[i] + numbers[j]);            
        }        
    }
    vector<int> ans;
    for(auto i : s) ans.push_back(i);
    sort(ans.begin(), ans.end());
    return ans;    
}