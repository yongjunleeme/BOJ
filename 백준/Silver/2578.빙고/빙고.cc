#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int a;
  int arr[5][5];
  int order = 0;
  
  
  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      cin >> arr[i][j];
    }
  }
  
  for (int k = 0; k < 25; k++)
  {
    cin >> a;
    order++;
    
    for (int i = 0; i < 5; i++)
    {
      for (int j = 0; j < 5; j++)
      {
        if (arr[i][j] == a) arr[i][j] = -1;
      }
    }
    
    int cnt = 0;
    
    for (int p = 0; p < 5; p++)
    {
      int Xcnt = 0;
      for (int q = 0; q < 5; q++)
      {
        if (arr[p][q] == -1) Xcnt++;
      }
      if (Xcnt == 5) cnt++;
    }
    
    for (int p = 0; p < 5; p++)
    {
      int Xcnt = 0;
      for (int q = 0; q < 5; q++)
      {
        if (arr[q][p] == -1) Xcnt++;
      }
      if (Xcnt == 5) cnt++;
    }
  
    if (arr[0][0] == -1 &&
        arr[1][1] == -1 &&
        arr[2][2] == -1 &&
        arr[3][3] == -1 &&
        arr[4][4] == -1) cnt++;
    
    if (arr[0][4] == -1 &&
        arr[1][3] == -1 &&
        arr[2][2] == -1 &&
        arr[3][1] == -1 &&
        arr[4][0] == -1) cnt++;
      
    if (cnt >= 3)
    {
      cout << order << endl;
      return 0;
    }
  }
  return 0;
}
