#include <bits/stdc++.h>
using namespace std;

int t, n, m;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  while(t--){
    cin >> n >> m;
    vector <pair<int, int>> v(n+m);

    for(int i = 0; i < n; i++){
      int a;
      cin >> a;
      v[i] = {a, 0};
    }
    for(int i = n; i < n+m; i++){
      int b;
      cin >> b;
      v[i] = {b, 1};
    }
    sort(v.begin(), v.end());
    int ans = 0;
    int cnt = 0;
    for(int i = 0; i < n+m; i++){
      if(v[i].second == 0) ans += cnt;
      else cnt++;
    }
    cout << ans << '\n';
  }
}
