#include <bits/stdc++.h>
using namespace std;

int n;
int arr[26];
int cnt = 0;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n;
  while(n--){
    bool flag = true;
    string s;
    cin >> s;
    fill(arr, arr+26, 0);
    if(s.size() == 1){
      cnt++;
      continue;
    }
    
    arr[s[0] - 'a'] = 1;
    for(int i = 1; i < s.size(); i++)
      if(s[i] != s[i-1]){
        if(!arr[s[i] - 'a']) arr[s[i] - 'a']++;
        else flag = false;
      }
    if(flag)cnt++;
    
  }
  cout << cnt;
}
