#include <bits/stdc++.h>
using namespace std;

int n;
string s;
vector<long long> v;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  while(n--){
    cin >> s;
    reverse(s.begin(), s.end());
    v.push_back(stoll(s));
  }
  sort(v.begin(), v.end());
  for(auto i: v) cout << i << '\n';
}
