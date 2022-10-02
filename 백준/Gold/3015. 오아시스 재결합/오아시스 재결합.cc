#include <bits/stdc++.h>
using namespace std;

int n;
long long ans;
stack <pair<int, int>> s;

int main(void){
  cin >> n;
  for(int i = 0; i < n; i++){
    int height;
    cin >> height;
    int cnt = 1;
    while(!s.empty() && s.top().first <= height){
      ans += s.top().second;
      if(s.top().first == height) cnt += s.top().second;
      s.pop();
    }
    if(!s.empty()) ans++;
    s.push({height, cnt});
  }
  cout << ans;
}
