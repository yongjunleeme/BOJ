#include <bits/stdc++.h>
using namespace std;

int n, t;
int a[1000005];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  
  while(t--){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    
    int m = a[n-1];
    long long ans = 0;
    
    for(int i = n - 2; i >= 0; i--){
      if(a[i] > m) m = a[i];
      ans += m - a[i];
    }
    
    cout << ans << '\n';
  }
}
