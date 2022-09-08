// https://velog.io/@gowoonsori/%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4cpp%EB%B2%A0%EC%8A%A4%ED%8A%B8%EC%95%A8%EB%B2%94

#include <bits/stdc++.h>
using namespace std;

bool compare(pair<string, int> a, pair<string, int> b){
    return a.second > b.second;
}

bool compare2(pair<int, int> a, pair<int, int> b){
    return a.first > b.first;
}


vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map <string,vector<pair<int,int>>> g_play_n;  // 장르, 재생횟수, 고유번호
    unordered_map <string,int> g_n; // 장르, 총 재생횟수
    
    
    for(int i = 0; i < genres.size(); i++){
        g_n[genres[i]] += plays[i];
        g_play_n[genres[i]].push_back(make_pair(plays[i], i));        
    }
    
    // 많이 재생된 장르를 먼저 수록
    vector <pair<string,int>> v;
    v.assign(g_n.begin(), g_n.end());
    sort(v.begin(), v.end(), compare);
    
    // 많이 재생된 노래를 먼저 수록
    for(auto &i: g_play_n)
        sort(i.second.begin(), i.second.end(), compare2);
    
    for(int i = 0; i < v.size(); i++){
        string genre = v[i].first;
        
        for(int j = 0; j < g_play_n[genre].size(); j++){
            if(j >= 2) continue;
            answer.push_back(g_play_n[genre][j].second);
        }
    }
    
    return answer;
}