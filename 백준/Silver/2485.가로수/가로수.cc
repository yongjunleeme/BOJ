#include <bits/stdc++.h>
using namespace std;

int getGCD(int a, int b)
{
  while(1)
  {
    int c = a % b;
    if (c == 0) return b;
    
    a = b;
    b = c;
  }
}


int main() {
  
  int n;
  int tree[100005];
  
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> tree[i];
  }
  
  int GCD = 0;
  
  for (int i = 0; i < n - 1; i++)
  {
    int distance = tree[i + 1] - tree[i];
    
    if (GCD == 0) GCD = distance;
    else GCD = getGCD(GCD, distance);
  }
  
  int totalTreeCnt = ((tree[n - 1] - tree[0]) / GCD) + 1;

  cout << totalTreeCnt - n;
  
  return 0;

}
