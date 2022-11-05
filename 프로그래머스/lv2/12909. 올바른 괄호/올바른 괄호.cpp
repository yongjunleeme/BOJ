#include <bits/stdc++.h>
using namespace std;

stack <char> stk;

bool solution(string s){
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '(' || stk.empty()) stk.push(s[i]);
        else if(s[i] == ')'){
            if(stk.top() == '(') stk.pop();
            else return false;
        }
    }
    if(stk.empty()) return true;
    else return false;
}