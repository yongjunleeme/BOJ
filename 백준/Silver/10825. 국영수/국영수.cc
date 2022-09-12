#include <bits/stdc++.h>
using namespace std;

int n;
vector <tuple<int, int, int, string>> v;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++){
    string d;
    int a, b, c;
    cin >> d >> a >> b >> c;
    v.push_back({-a,b,-c,d});
  }
  sort(v.begin(), v.end());
  for(auto&i : v) cout << get<3>(i) << '\n';
}
