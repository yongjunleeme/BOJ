#include <bits/stdc++.h>
using namespace std;

#include <stdio.h>

int result[100], resultLen;
int n;
bool isFinished = false;


bool isPossible(int x, int length)
{
  // result[x]가 오른쪽 끝이고, 길이 length의 중복이 있는지 판별.
  // 중복이 없다면 true, 아니면 false
  
  for (int i = 0; i < length; i++)
  {
    if (result[x - i] != result[x - i - length])
      return true;
  }
  
  return false;
}

void getResult(int x)
{
  // result[x] ~ result[n - 1]까지 결정하는 함수
  
  // 1) x번째 숫자 결정
  // 2) x + 1 번째 숫자 결정
  
  //  0 1 2 3 4 5 6 7   8  getResult(8)
  //  1 2 1 3 1 2 3 1   2
  
  // ###
  //길이 1-->        1   2
  //길이 2-->    2 3 1   2
  //길이 3-->3 1 2 3 1   2
  
  
  if (isFinished == true) return;
  
  if (x >= n)
  {
    for (int i = 0; i < n; i++) printf("%d", result[i]);
    printf("\n");
    
    isFinished = true;
    return;
  }
  
  for (int i = 1; i <= 3; i++)
  {
    result[x] = i;
    bool flag = false; // 안 되는 신호 잡기
    for (int j = 1; j <= (x + 1) / 2; j++) // j는 ### 길이를 나타냄, 남아 있는 숫자와 비교해야 하므로 절반
    {
      if (!isPossible(x, j))
      {
        flag = true;
        break;
      }
    }
    
    if (flag == false)
    {
      getResult(x + 1);
    }
  }
}

int main()
{
  scanf("%d", &n);
  getResult(0);
  return 0;
}
