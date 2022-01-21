#include <bits/stdc++.h>
using namespace std;

int n;
int arr[10];
int ans = 0;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++) cin >> arr[i];
  sort(arr, arr+n);
  
  do{
    int tmp = 0;
    for(int i = 0; i < n-1; i++)
      tmp += abs(arr[i] - arr[i+1]);
    ans = max(tmp, ans);
  }while(next_permutation(arr, arr+n));
  cout << ans;
}
