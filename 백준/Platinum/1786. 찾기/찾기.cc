#include <bits/stdc++.h>
using namespace std;

vector<int> getPi(string p){
  int j = 0;
  
  vector<int> pi(p.size(), 0);
  for(int i = 1; i < p.size(); i++){
    while(j > 0 && p[i] != p[j])
      j = pi[j - 1];
    
    if(p[i] == p[j]) pi[i] = ++j;
  }
  return pi;
}

vector<int> kmp(string s, string p){
  vector<int> ans;
  vector<int> pi = getPi(p);
  int j = 0;
  
  for(int i = 0; i < s.size(); i++){
    
    while(j > 0 && s[i] != p[j])
      j = pi[j - 1];
    
    if(s[i] == p[j]){
      if(j == p.size() - 1){
        ans.push_back(i - (int)p.size() + 1);
        j = pi[j];
      }
      else j++;
    }
  }
  return ans;
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  string s, p;
  getline(cin, s);
  getline(cin, p);
  
  auto matched = kmp(s, p);
  cout << matched.size() << '\n';
  for(auto i : matched)
    cout << i+1 << '\n';
}