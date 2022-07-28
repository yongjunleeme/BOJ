#include <bits/stdc++.h>
using namespace std;

int t;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n, m;
  unordered_map<string, int> s2i;
  string i2s[100005];
  string a;
  
  cin >> n >> m;
  for(int i = 1; i <= n; i++){
    cin >> i2s[i];
    s2i[i2s[i]] = i;
  }
  
  while(m--){
    cin >> a;
    if(isdigit(a[0])) cout << i2s[stoi(a)] << '\n';
    else cout << s2i[a] << '\n';
  }
}
