#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0 , -1};
int board[5][5];
int num = 0;
set<int> s;

void func(int x, int y, int k){
  if(k == 6){
    s.insert(num);
    return;
  }
  
  int tmp;
  for(int dir = 0; dir < 4; dir++){
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if(nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
    tmp = num;
    num = (num * 10) + board[nx][ny];
    func(nx, ny, k+1);
    num = tmp;
  }
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  for(int i = 0; i < 5; i++)
    for(int j = 0; j < 5; j++) cin >> board[i][j];
  
  for(int i = 0; i < 5; i++)
    for(int j = 0; j < 5; j++) func(i, j, 0);
  cout << s.size();
}
