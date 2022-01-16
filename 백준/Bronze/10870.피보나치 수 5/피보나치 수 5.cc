#include <bits/stdc++.h>
using namespace std;

int n;

int func(int k){
  if(k == 0) return 0;
  if(k == 1) return 1;
  return func(k-1) + func(k-2);
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  cout << func(n);
}
