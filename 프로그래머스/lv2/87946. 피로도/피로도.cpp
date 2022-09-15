#include <bits/stdc++.h>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;
    vector <int> brute;
    for(int i = 0; i < dungeons.size(); i++) brute.push_back(i);
    
    do{        
        int kk = k;
        int cnt = 0;
        for(int i = 0; i < brute.size(); i++){
            if(kk >= dungeons[brute[i]][0]) kk -= dungeons[brute[i]][1];
            else break;
            cnt++;
        }
        answer = max(cnt, answer);
    }while(next_permutation(brute.begin(), brute.end()));
    return answer;
}