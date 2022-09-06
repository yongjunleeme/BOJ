#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> m;

string solution(vector<string> participant, vector<string> completion) {    
    for(int i = 0; i < participant.size(); i++) m[participant[i]]++;
    for(int i = 0; i < completion.size(); i++) m[completion[i]]--;    
    for(auto a: m) if(a.second > 0) return a.first;    
}