#include <bits/stdc++.h>
using namespace std;

int a, n, k;
bool occur[2000005];
int num[1000005];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n;
  for(int i = 0; i < n; i++) cin >> num[i];
  cin >> k;
  
  int ans = 0;
  for(int i = 0; i < n; i++){
    if(k - num[i] > 0 && occur[k - num[i]]) ans++;
    occur[num[i]] = true;
  }
  
  cout << ans;
}
