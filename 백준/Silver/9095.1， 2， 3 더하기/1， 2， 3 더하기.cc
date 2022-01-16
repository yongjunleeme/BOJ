#include <bits/stdc++.h>
using namespace std;

int n;
int arr[12];

int solve(int n){
    
    if(n == 1) return 1;
    if(n == 2) return 2;
    if(n == 3) return 4;
    
    if(arr[n] != -1) return arr[n];
    return arr[n] = solve(n - 1) + solve(n - 2) + solve(n - 3);
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        fill(arr, arr + 12, -1);
        cout << solve(n) << "\n";
    }
}
