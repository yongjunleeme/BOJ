#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    
    while (t--)
    {
        string a;
        cin >> a;
        
        stack <int> S;		
        
        for (auto c: a) {
            if (!S.empty())
            {
                if (S.top() == '(' && c == ')') S.pop();
                else S.push(c);
            }
            else S.push(c);
        }
        if (S.empty()) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
}