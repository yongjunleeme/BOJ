#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {    
    map<string, int> s2i; // id, idx
    set<int> s[1005]; // s[idx] : idx를 신고한 사람들의 집합
    int n = id_list.size();
    vector<int> ans(n); // 신고 당한 사람이 아니라 신고한 사람

    for(int i = 0; i < n; i++) s2i[id_list[i]] = i;
    
    for(auto rep: report){
        stringstream st(rep);
        string id1, id2;
        st >> id1 >> id2;
        s[s2i[id2]].insert(s2i[id1]);
    }
    
    for(int i = 0; i < n; i++){
        if(s[i].size() < k) continue;
        for(auto ix : s[i]) ans[ix]++;
    }
    
    return ans;
}