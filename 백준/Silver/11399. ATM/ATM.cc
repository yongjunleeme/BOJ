#include <bits/stdc++.h>
using namespace std;

int n;
int p[1005];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++) cin >> p[i];
  sort(p, p+n);
  
  int ans = 0;
  
  for(int i = 0; i < n; i++)
    for(int j = 0; j <= i; j++)
      ans += p[j];
  
  cout << ans;
}
