#include <bits/stdc++.h>

using namespace std;

int func(int k){
    if(k == 6) return 1;
    if(k == 5) return 2;
    if(k == 4) return 3;
    if(k == 3) return 4;
    if(k == 2) return 5;
    if(k == 1) return 6;
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    ios::sync_with_stdio(0);
    cin.tie(0);   
    
    int num_zero = 0;
    int score = 0;
    for(auto i : lottos){
        if (i == 0) num_zero++;
        else {
            for(auto j : win_nums)
                if(i == j) score++;
        }
    }
    int mx = score + num_zero;
    vector<int> answer;
    answer.push_back(func(mx));
    answer.push_back(func(score));  
    
    return answer;
}