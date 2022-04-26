#include <bits/stdc++.h>
using namespace std;

int n;
int isused1[40];
int isused2[40];
int isused3[40];
int cnt = 0;

// isused1 --> y       column (세로)
// isused2 --> x+y     / (우측 상단 대각선)
// isused3 --> x-y+n-1 \ (좌측 하단 대각선, n-1은 index 음수방지)

void func(int cur){ //isused의 index와 func의 k를 x, y좌표로 삼는다.
  if(cur == n){
    cnt++;
    return;
  }
  for(int i = 0; i < n; i++){
    if(isused1[i] || isused2[cur+i] || isused3[cur-i+n-1]) continue;
    isused1[i] = 1;
    isused2[cur+i] = 1;
    isused3[cur-i+n-1] = 1;
    func(cur+1);
    isused1[i] = 0;
    isused2[cur+i] = 0;
    isused3[cur-i+n-1] = 0;
  }
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  func(0);
  cout << cnt;
}
