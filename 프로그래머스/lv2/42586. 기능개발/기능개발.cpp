#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector <int> tmp;
    vector <int> ans;
    stack <int> stk;
    for(int i = 0; i < progresses.size(); i++){
        tmp.push_back((99 - progresses[i]) / speeds[i] + 1);
    }
    for(int i = 0; i < tmp.size(); i++){
        if(ans.empty() || tmp[i] > stk.top()) ans.push_back(1);
        else ans.back()++;
        
        if(stk.empty() || stk.top() < tmp[i]) stk.push(tmp[i]);
        
    }
    return ans;
}