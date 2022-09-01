#include <bits/stdc++.h>
using namespace std;

int n, a;

int main(void){
  cin >> n;
  for(int i = 1; i <= n; i *= 10){
    a += n - i + 1;
  }
  cout << a;
}
