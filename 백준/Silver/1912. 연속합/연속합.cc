#include <bits/stdc++.h>
using namespace std;

int n;
int d[100005];
int a[100005];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  // 연속합 최대값
  cin >> n;
  
  for(int i = 1; i <= n; i++){
    cin >> a[i];
    d[i] = a[i];
  }
  
  for(int i = 1; i <= n; i++)
    d[i] = max(d[i-1] + d[i], d[i]);
  
  cout << *max_element(d+1, d+n+1);
}
