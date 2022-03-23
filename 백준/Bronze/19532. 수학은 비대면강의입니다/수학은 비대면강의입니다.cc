#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> V(6);
    for(int i=0;i<6;i++) cin >> V[i];

    for(int x = -1000; x <= 1000; x++) {
        for(int y = -1000; y <= 1000; y++) {
            int F = V[0] * x + V[1] * y - V[2];
            int S = V[3] * x + V[4] * y - V[5];
            if(F == 0 && S == 0) cout << x << ' ' << y;
            
        }
    }
}