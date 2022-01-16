#include <bits/stdc++.h>
using namespace std;
// 가장 작은 수, 가장 큰 수부터 구해보면 빨리 구할 수 있다.

int n;
int result[15];
char myInput[15];
bool checkMax[10], checkMin[10];
bool printMax = false, printMin = false;

void getMax(int x)
{
  //x번째 숫자를 결정. result[x]를 결정
  if (printMax == true) return;
  
  if (x > n)
  {
    for (int i = 0; i < n + 1; i++)
    {
      printf("%d", result[i]);
    }
    printf("\n");
    
    printMax = true; // 최초에 가장 큰 수만 출력하기 위해
  }
  
  else
  {
    for (int i = 9; i >= 0; i--)
    {
      result[x] = i;
      
      if (checkMax[i] == false)
      // result[x - 1]               result[x]
      //               myInput[x - 1]
       
      //  0   1
      //  <   >    <--- myinput
      
      // 0   1   2
      //        <-- result
      {
        bool flag = false;
        
        if (x == 0) flag = true; // 첫 번째는 부등호 관계가 없기 때문에 뭐든 넣어도 된다.
        else
        {
          if (myInput[x - 1] == '>')
          {
            if (result[x - 1] > result[x]) flag = true;
          }
          else // '<'
          {
            if (result[x - 1] < result[x]) flag = true;
          }
        }
        if (flag == true)
        {
          checkMax[i] = true;
          getMax(x + 1);
          checkMax[i] = false;  // x자리에서 i를 뺸다? 무슨 말??
        }
      }
    }
  }
}

void getMin(int x)
{
  //x번째 숫자를 결정. result[x]를 결정
  if (printMin == true) return;
  
  if (x > n)
  {
    for (int i = 0; i < n + 1; i++)
    {
      printf("%d", result[i]);
    }
    printf("\n");
    
    printMin = true;
  }
  
  else
  {
    for (int i = 0; i <= 9; i++)
    {
      result[x] = i; // 지금까지 넣어본 적이 없었어야 한다. 한 번밖에 못 넣기 때문에
      
      if (checkMin[i] == false)
      {
        bool flag = false;
        
        if (x == 0) flag = true;
        else
        {
          if (myInput[x - 1] == '>')
          {
            if (result[x - 1] > result[x]) flag = true;
          }
          else // '<'
          {
            if (result[x - 1] < result[x]) flag = true;
          }
        }
        if (flag == true)
        {
          checkMin[i] = true;
          getMin(x + 1);
          checkMin[i] = false;
        }
      }
    }
  }
}

int main()
{
  scanf("%d", &n);
  
  for (int i = 0; i < n; i++)
  {
    scanf(" %c", &myInput[i]); // 일반 부등호 이외 모든 input 받기 위해 " %c"를 사용
  }
  
  getMax(0);
  getMin(0);
  
  return 0;
}
