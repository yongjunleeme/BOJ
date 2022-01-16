#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  fill(arr+m, arr+n, 1);
  do{
    for(int i = 0; i < n; i++)
      if(!arr[i]) cout << i+1 << "\n";
  }while(next_permutation(arr, arr+n));
}
