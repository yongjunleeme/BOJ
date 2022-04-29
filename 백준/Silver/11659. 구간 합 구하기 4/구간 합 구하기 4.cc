#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[100004], d[100004];

// 테이블
// d[i] = 1부터 i까지의 합
  
// 점화식
// d[i] = d[i-1] + a[i];

// 초기값
// d[0] = 0;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  d[0] = 0;
  for(int i = 1; i <= n; i++){
    cin >> a[i];
    d[i] = d[i-1] + a[i];
  }
  while(m--){
    int i, j;
    cin >> i >> j;
    cout << d[j] - d[i-1] << '\n'; // i-1은 범위 이전의 수를 뺀다.
  }
}
