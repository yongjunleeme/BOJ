#include <bits/stdc++.h>
using namespace std;

string s;
vector<string> v;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> s;
  for(int i = 0; i < s.size(); i++){
    string a = s.substr(i, s.size() - i);
    v.push_back(a);
  }
  sort(v.begin(), v.end());
  for(auto i : v) cout << i << '\n';
}
