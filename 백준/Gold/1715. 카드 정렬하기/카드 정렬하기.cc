#include <bits/stdc++.h>
using namespace std;

int n;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int ans = 0;
  
  cin >> n;
  priority_queue<int, vector<int>, greater<int>> pq;
  for(int i = 0; i < n; i++){
    int a;
    cin >> a;
    pq.push(a);
  }
  while(pq.size() > 1){
    int x = pq.top(); pq.pop();
    int y = pq.top(); pq.pop();
    ans += x + y;
    pq.push(x+y);
  }
  cout << ans;
}
