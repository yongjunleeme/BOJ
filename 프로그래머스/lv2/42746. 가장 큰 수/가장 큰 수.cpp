#include <bits/stdc++.h>

using namespace std;

bool cmp(string a, string b){
    return a+b > b+a;
}

string solution(vector<int> numbers) {
    vector <string> tmp;
    for(int i = 0; i < numbers.size(); i++){        
        tmp.push_back(to_string(numbers[i]));
    }
    
    
    sort(tmp.begin(), tmp.end(), cmp);
    
    if(tmp[0] == "0") return "0";
    
    string answer = "";
    for(int i = 0; i < tmp.size(); i++){        
        answer += tmp[i];
    }    
    return answer;
}