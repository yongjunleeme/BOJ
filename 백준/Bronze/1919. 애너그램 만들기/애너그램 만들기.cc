#include <bits/stdc++.h>
using namespace std;

int n;
int arr[26];
string a, b;
int ans = 0;

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> a >> b;
  for (auto c : a) arr[c - 'a']++;
      
  for (auto c : b) arr[c - 'a']--;
  
  for (int j = 0; j < 26; j++)
      ans += abs(arr[j]);
  
  cout << ans;
  
   
}