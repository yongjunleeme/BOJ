#include <bits/stdc++.h>

using namespace std;


string solution(int n) {
    string answer = "";
    vector <char> v = {'4', '1', '2'};
    
    while(n){
        int a = n % 3;
        answer += v[a];
        
        if(n % 3 == 0) n = (n / 3) - 1;
        else n /= 3;        
        
    }
    reverse(answer.begin(), answer.end());
    return answer;        
}