#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
ll d[100];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n;
  d[1] = 1;
  d[2] = 1;
  for(int i = 3; i <= n; i++){
    d[i] = d[i-1] + d[i-2];
  }
  cout << d[n];
}
