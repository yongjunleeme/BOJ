#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

vector<pair<int, int>> v;
int n, a = 1;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    v.push_back({a, b});
  }
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++)
      if(v[i].X < v[j].X && v[i].Y < v[j].Y) a++;
    cout << a << " ";
    a=1;
  }
}
