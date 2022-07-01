#include <bits/stdc++.h>
using namespace std;

int a[10];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n;
  cin >> n;
  
  while(n > 0){
    a[n%10]++;
    n /= 10;
  }
  
  int ans = 0;
  for(int i = 0; i < 10; i++){
    if(i == 6 || i == 9) continue;
    ans = max(ans, a[i]);
  }
  
  ans = max(ans, (a[6] + a[9] + 1) / 2);
  cout << ans;
}
