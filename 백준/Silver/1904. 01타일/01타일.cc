#include <bits/stdc++.h>
using namespace std;

int n;
int d[1000005];
int mod = 15746;


int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  d[1] = 1;
  d[2] = 2;
  
  for(int i = 3; i <= n; i++)
    d[i] = (d[i-1] + d[i-2]) % mod;
  
  cout << d[n];
}
