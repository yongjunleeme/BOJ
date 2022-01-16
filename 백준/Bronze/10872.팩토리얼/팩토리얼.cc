#include <bits/stdc++.h>
using namespace std;

int n;

int func(int k){
  if(k < 1) return 1;
  return k * func(k-1);
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  cout << func(n);
}
