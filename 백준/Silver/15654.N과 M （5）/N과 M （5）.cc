// 종이의 개수, N-Queen, 부분수열 복습

#include <bits/stdc++.h>
using namespace std;

int isused[10];
int arr[10];
int num[10];
int n, m;

void func(int k){
  if(k == m){
    for(int i = 0; i < m; i++) cout << num[arr[i]] << " ";
    cout << "\n";
    return;
  }
  for(int i = 0; i < n; i++){
    if(!isused[i]){
      arr[k] = i;
      isused[i] = 1;
      func(k+1);
      isused[i] = 0;
    }
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for(int i = 0; i < n; i++) cin >> num[i];
  sort(num, num+n);
  func(0);
}
