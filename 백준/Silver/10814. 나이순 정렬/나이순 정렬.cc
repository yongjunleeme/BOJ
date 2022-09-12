#include <bits/stdc++.h>
using namespace std;

int n;
vector <pair<int, string>> v;

bool cmp(pair<int, string> a, pair<int, string> b){
  return a.first < b.first;
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n;
  for(int i = 0; i < n; i++){
    int a;
    string b;
    cin >> a >> b;
    
    v.push_back({a, b});
  }
  stable_sort(v.begin(), v.end(), cmp);
  
  for(auto i: v) cout << i.first << ' ' << i.second << '\n';
}
