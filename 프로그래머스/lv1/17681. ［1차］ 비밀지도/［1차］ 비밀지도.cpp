#include <bits/stdc++.h>
using namespace std;


string i2str2(int x, int n) {
    string ret(n, ' ');
    for(int i = 0; i < n; i++){
        if(x % 2 == 1) ret[n-1-i] = '#';
        x /= 2;
    }
    return ret;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer(n);
    for(int i = 0; i < n; i++){
        answer[i] = i2str2(arr1[i] | arr2[i], n);
    }
    return answer;
}