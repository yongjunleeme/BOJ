#include <bits/stdc++.h>
using namespace std;


int n, a;
int arr[205];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> a;
    arr[100+a]++;
  }
  int k;
  cin >> k;
  
  cout << arr[100+k];
  
}
