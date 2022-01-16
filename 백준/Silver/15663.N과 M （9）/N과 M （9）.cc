// 종이의 개수, N-Queen, 부분수열 복습

#include <bits/stdc++.h>
using namespace std;

int isused[10];
int arr[10];
int num[10];
int n, m;

void func(int k){
  if(k == m){
    for(int i = 0; i < m; i++) cout << arr[i] << " ";
    cout << "\n";
    return;
  }
  int tmp = -1;
  for(int i = 0; i < n; i++){
    if(!isused[i] && num[i] != tmp){  // 이전 수열의 마지막 항과 새로운 수열의 마지막 항이 같으면 중복 수열
      arr[k] = num[i];
      tmp = arr[k];
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
