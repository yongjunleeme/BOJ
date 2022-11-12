#include <bits/stdc++.h>
using namespace std;

int d1[1000005];
int d2[1000005];

// https://yabmoons.tistory.com/477

int solution(vector<int> money) {
    d1[0] = money[0];
    d1[1] = d1[0];
    
    d2[0] = 0;
    d2[1] = money[1];
    
    for(int i = 2; i < money.size() - 1; i++){
        d1[i] = max(money[i] + d1[i-2], d1[i-1]);
    }
    
    for(int i = 2; i < money.size(); i++){
        d2[i] = max(money[i] + d2[i-2], d2[i-1]);
    }
    cout << max(d1[money.size()-1], d2[money.size()-1]);
    
    return max(d1[money.size()-2], d2[money.size()-1]);
}