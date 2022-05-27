#include <bits/stdc++.h>
using namespace std;

int n, a;
int d[1000005];
int mod = 1e9 + 9;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  d[1] = 1;
  d[2] = 2;
  d[3] = 4;
  
  for(int i = 4; i <= 1000000; i++)
    for(int j = 1; j <= 3; j++)
      d[i] = (d[i-j] + d[i]) % mod;
    
  
  cin >> n;
  while(n--){
    cin >> a;
    cout << d[a] << '\n';
  }
}
