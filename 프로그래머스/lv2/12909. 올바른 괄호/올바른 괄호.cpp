#include <bits/stdc++.h>
using namespace std;

stack <char> a;

bool solution(string s)
{
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '(') a.push(s[i]);
        else {
            if(!a.empty()){
                a.pop();
            }else{
                return false;
            }
        }
    }
    if(a.empty()) return true;
    else return false;
}