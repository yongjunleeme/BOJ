#include <bits/stdc++.h>
using namespace std;

string solution(string new_id) {
    string id1;
    for(auto i : new_id) id1 += tolower(i);
    
    string step2_filter = "0123456789abcdefghijklmnopqrstuvwxyz-_.";
    
    string id2;
    for(auto i : id1){
        if(find(step2_filter.begin(), step2_filter.end(), i) != step2_filter.end()) id2 += i;
    }
    
    string id3;
    for(auto i : id2){
        if(i != '.') id3 += i;
        else {
            if(!id3.empty() && id3.back() == '.') continue;
            id3 += i;
        }
    }
    
    string id4;
    for(int i = 0; i < id3.size(); i++){
        if((i == 0 || i == id3.size()) && id3[i] == '.') continue;
        id4 += id3[i];
    }
    
    string id5 = id4;
    if(id4.empty()) id5 = "a";    
    
    string id6 = id5.substr(0, 15);
    if(id6.back() == '.') id6.pop_back();
    
    string id7 = id6;
    while(id7.size() < 3){
        id7 += id7.back();                
    }
       
    
    return id7;           
}