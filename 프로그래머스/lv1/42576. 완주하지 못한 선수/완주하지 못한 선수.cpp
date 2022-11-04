#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> m;

string solution(vector<string> participant, vector<string> completion) {
    unordered_set <string> s;
    for(int i = 0; i < participant.size(); i++) m[participant[i]]++;
    for(int i = 0; i < completion.size(); i++) m[completion[i]]--;
    for(auto i: m) if(i.second) return i.first;
    
}