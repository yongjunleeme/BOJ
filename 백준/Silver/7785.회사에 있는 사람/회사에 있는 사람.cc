#include <bits/stdc++.h>
using namespace std;

int n;
unordered_map<string, string> m;
vector <string> ans;
int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  string a, b;
  while(n--){
    cin >> a >> b;
    m[a] = b;
  }
  int num = 0;
  for(auto e : m){
    if(e.second == "enter"){
      ans.push_back(e.first);
      num++;
    }
  }
  sort(ans.begin(), ans.end());
  for(int i = num - 1; i >= 0 ; i--) cout << ans[i] << '\n';
  
}
