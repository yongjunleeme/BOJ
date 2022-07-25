#include <bits/stdc++.h>
using namespace std;

int n;
int arr[40005];
int dp[40005];

int binarySearch(int st, int en, int target){
  
  int ans= 0;
  while(st <= en){
    int mid = (st + en) / 2;
    if(dp[mid] >= target){
      ans = mid;
      en = mid-1;
    }else st = mid+1;
  }
  return ans;
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n;
  for(int i = 0; i < n; i++) cin >> arr[i];
  
  dp[0]= arr[0];
  int idx = 0;
  
  for(int i = 1; i < n; i++){
    if(arr[i] > dp[idx]){
      dp[++idx] = arr[i];
    } else {
      dp[binarySearch(0, idx, arr[i])] = arr[i];
    }
//    for(int i = 0; i < n; i++) cout << dp[i] << ' ';
//    cout << '\n';
  }
  
  cout << idx+1;
}
