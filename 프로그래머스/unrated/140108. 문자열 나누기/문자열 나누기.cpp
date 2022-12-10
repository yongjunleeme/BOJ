#include <bits/stdc++.h>

using namespace std;

int solution(string s) {
    char tmp = s[0];
    int cnt = 1;
    int ans = 0;
    for(int i = 1; i < s.size(); i++){
        if(cnt == 0) tmp = s[i];
        if(s[i] == tmp) cnt++;
        else cnt--;
        if(cnt == 0) ans++;
    }
    if(cnt > 0) ans++;
    return ans;
}