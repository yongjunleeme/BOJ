#include <bits/stdc++.h>
using namespace std;
int n;
const int MAX = 64;
int board[MAX][MAX];


void solve(int n, int x, int y){
    if(n == 1){
        cout << board[x][y];
        return;
    }
    bool zero = true, one = true;
    for(int i = x; i < x + n; i++)
        for(int j = y; j < y + n; j++)
            if(board[i][j]) zero = false;
            else one = false;
    
    if(zero) cout << 0;
    else if(one) cout << 1;
    else{
        cout << "(";
        solve(n/2, x, y);
        solve(n/2, x, y+n/2);
        solve(n/2, x+n/2, y);
        solve(n/2, x+n/2, y+n/2);
        cout << ")";
    }
    return;
}


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        for(int j = 0; j < n; j++) board[i][j] = s[j] - '0';
    }
    
    solve(n, 0, 0);
}