#include <bits/stdc++.h>
using namespace std;

int n, m;
int isused[10];
int arr[10];
int num[10];

void func(int k){
  if(k == m){
    for(int i = 0; i < m; ++i)
      cout << arr[i] << " ";
    cout << "\n";
    return;
  }
  for(int i = 0; i < n; ++i){
    arr[k] = num[i];
    func(k+1);
  }
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  int idx = 0;
  bool chk[10002];
  while(n--){
    cin >> num[idx];
    if(chk[num[idx]]) continue;
    chk[num[idx]] = 1;
    idx++;
  }
  n = idx;
  sort(num, num+n);
  func(0);
}
