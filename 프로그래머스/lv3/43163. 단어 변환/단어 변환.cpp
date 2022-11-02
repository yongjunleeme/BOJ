#include <bits/stdc++.h>

using namespace std;

int vis[55];
int ans = 100;

void func(string target, vector<string> words, string begin, int res){
    if(target == begin){
        ans = res;
        return;
    }
    for(int i = 0; i < words.size(); i++){
        int cnt = 0;
        for(int j = 0; j < words[i].size(); j++){
            if(begin[j] != words[i][j]) cnt++;
            if(cnt == 2) break;
        }
        if(cnt == 1){
            if(!vis[i]){
                vis[i] = 1;
                func(target, words, words[i], res+1);
                vis[i] = 0;
            }
        }
    }
    
}

int solution(string begin, string target, vector<string> words) {    
    func(target, words, begin, 0);
    if (ans == 100) ans = 0;
    return ans;
}