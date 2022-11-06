#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> ans;
    for(int i = 0; i < commands.size(); i++){
        int st = commands[i][0];
        int en = commands[i][1];
        vector <int> tmp;
        for(int j = st-1; j < en; j++){
            tmp.push_back(array[j]);
        }
        sort(tmp.begin(), tmp.end());
        ans.push_back(tmp[commands[i][2]-1]);
    }
    return ans;
}