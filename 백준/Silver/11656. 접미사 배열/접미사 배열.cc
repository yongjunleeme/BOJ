#include <bits/stdc++.h>
using namespace std;

string s;
vector <string> v;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> s;
  int len = s.size();
  int idx = 0;
  while(idx < len){
    string a;
    for(int i = idx; i < len; i++) a += s[i];
    idx++;
    v.push_back(a);
  }
  sort(v.begin(), v.end());
  for(auto i: v) cout << i << '\n';  
}
