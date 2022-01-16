#include <bits/stdc++.h>
using namespace std;

int k, s;
int arr[15];
int num[15];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  while(1){
    cin >> k;
    if(!k) break;
    for(int i = 0; i < k; i++) cin >> arr[i];
    fill(num+6, num+k, 1);
    
    do{
      for(int i = 0; i < k; i++)
        if(!num[i]) cout << arr[i] << " ";
      cout << "\n";
    }while(next_permutation(num, num+k));
    cout << "\n";
  }
}
