#include <bits/stdc++.h>
using namespace std;

int vis[10005];
vector <string> ans;
bool flag = false;

void func(string cur, vector<vector<string>> tickets){
    if(ans.size() == tickets.size()) flag = true;
    ans.push_back(cur);
    for(int i = 0; i < tickets.size(); i++){
        if(tickets[i][0] == cur && !vis[i]){
            vis[i] = 1;
            
            func(tickets[i][1], tickets);
            
            if(!flag){
                ans.pop_back();
                vis[i] = 0;
                flag = false;
            }
        }
    }
}


vector<string> solution(vector<vector<string>> tickets){
    sort(tickets.begin(), tickets.end());
    func("ICN", tickets);
    return ans;
}
