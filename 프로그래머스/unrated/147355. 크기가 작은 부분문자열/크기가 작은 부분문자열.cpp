#include <bits/stdc++.h>

using namespace std;

int solution(string t, string p) {
    int ans = 0;
    for(int i = 0; i < t.size() - p.size() + 1; i++){
        bool flag = false;
        int idx = i;
        for(int j = 0; j < p.size(); j++){
            cout << t[idx] << ' ' << p[j] - '0' << ' ' << ans << '\n' ;
            if(t[idx] - '0' > p[j] - '0') {
                flag = false;
                break;
            }
            else if(t[idx] - '0' < p[j] - '0'){
                flag = true;
                break;
            } else {
                flag = true;                
            }
            idx++;
        }
        if (flag) ans++;
            
    }
    return ans;
}