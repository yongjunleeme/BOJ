#include <bits/stdc++.h>
using namespace std;

int n, s[10], w[10];
int mx = 0, cnt = 0;

void func(int k){
  if(k == n){
    mx = max(mx, cnt);
    return;
  }
  if(s[k] <= 0 || cnt == n-1){
    func(k+1);
    return;
  }
  for(int i = 0; i < n; i++){
    if(i == k || s[i] <= 0) continue; // 지금 들고 있는 계란이거나 깨진 계란이라면
    s[k] -= w[i];
    s[i] -= w[k];
    if(s[k] <= 0) cnt++;
    if(s[i] <= 0) cnt++;
    func(k+1);
    if(s[k] <= 0) cnt--; // 다음 과정을 위해 원상복구
    if(s[i] <= 0) cnt--;
    s[k] += w[i];
    s[i] += w[k];
  }
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++) cin >> s[i] >> w[i];
  func(0);
  cout << mx;
}
