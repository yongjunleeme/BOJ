#include <bits/stdc++.h>
using namespace std;

string lower(string id){
    string s;
    for(auto i: id)
        s += tolower(i);
    return s;
}

string check2(string id){
    string ret;
    for(int i = 0; i < id.size(); i++){
        char a = id[i];
        if(!isdigit(a) && !isalpha(a) && a != '.' && a != '_' && a != '-' && a != '.') continue;
        ret += a;
    }                
    return ret;
}

string check3(string id){
    string ret;
    if(id.size() > 0 ) ret += id[0];
    for(int i = 1; i < id.size(); i++){
        if(id[i-1] == '.' && id[i] == '.') continue;
        ret += id[i];
        
    }
    return ret;
}

string check4(string id){
    
    if(id.size() > 0){        
        if(id[0] == '.') id.erase(id.begin(), id.begin()+1);        
    }
    if(id.size() > 0){
        if(id[id.size()-1] == '.') id.pop_back();
    }
    return id;
}


string solution(string new_id) {
    string ans = lower(new_id);
    
    ans = check2(ans);    
    
    ans = check3(ans);    
    
    ans = check4(ans);
    
    if(ans.size() == 0) ans+="a";
    
    if(ans.size() > 15) ans = ans.substr(0, 15);
    
    if(ans[ans.size()-1] == '.') ans.pop_back();
    
    if(ans.size() < 3){
        char a = ans[ans.size() -1];
        while(1){
            if(ans.size() >= 3) break;
            ans += a;
        }
    }
    
    
    return ans;
}