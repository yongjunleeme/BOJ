#include <bits/stdc++.h>
using namespace std;

int n, m;
vector <int> a;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  
  for(int i = n; i <= m; i++){
    bool isPrime = true;
    if(i == 1) continue;
    for(int j = 2; j*j <= i; j++){
      if(i % j == 0){
        isPrime = false;
        break;
      }
    }
    if(isPrime) a.push_back(i);
  }
  if(a.empty()) cout << -1;
  else{
    int sum = 0;
    for(int i: a) sum += i;
    cout << sum << '\n' << a[0];
  }
}
