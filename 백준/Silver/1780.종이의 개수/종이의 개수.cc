#include <bits/stdc++.h>
using namespace std;
int n;
int board[2200][2200];
int cnt[3];


bool check(int x, int y, int n){
    for(int i = x; i < x + n; i++)
        for(int j = y; j < y + n; j++)
            if(board[x][y] != board[i][j]) return false;
    return true;
}


void solve(int x, int y, int n){
    if(check(x, y, n)){
        cnt[board[x][y] + 1] += 1;
        return;
    }
    int nn = n / 3;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            solve(x+i*nn, y+j*nn, nn);
}


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> board[i][j];
    
    solve(0, 0, n);
    for(int i = 0; i < 3; i++) cout << cnt[i] << "\n";
}