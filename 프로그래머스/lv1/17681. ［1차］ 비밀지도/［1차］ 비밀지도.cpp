#include <bits/stdc++.h>

using namespace std;

string func(int a, int n){
    string ret(n, ' ');
    for(int i = 0; i < n; i++){
        if(a & (1 << i)) ret[n-1-i] = '#';
    }
    return ret;    
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    for(int i = 0; i < n; i++){
        answer.push_back(func(arr1[i] | arr2[i], n));
    } 
    
    
    
    return answer;
}