#include <bits/stdc++.h>
using namespace std;

int n;
int arr[1000004];
int ans[1000004];
stack <int> s;
int main(void){
  cin >> n;
  for(int i = 0; i < n; i++) cin >> arr[i];
  
  for(int i = n-1; i >= 0; i--){
    while(!s.empty() && arr[i] >= s.top()){
      s.pop();
    }
    if(s.empty()) ans[i] = -1;
    else ans[i] = s.top();
    s.push(arr[i]);
  }
  for(int i = 0; i < n; i++) cout << ans[i] << ' ';
}
