#include <stdio.h>
#include <string.h>

int main()
{
	char paren[50];
	int paren_len;
	int myStack[50], myTop = 0;
	
	scanf("%s", paren);
	paren_len = strlen(paren);
	
	for (int i = 0; i < paren_len; i++)
	{
		if (paren[i] == '(' || paren[i] == '[') // ( --> -1, [ --> -2
		{
			if (paren[i] == '(') myStack[myTop++] = -1;
			else myStack[myTop++] = -2;
		}
		else
		

		// 1) 스택 맨 위에 여는 괄호가 있는 경우
				//1.1) 스택 맨 위의 여는 괄호 pop
				//1.2) 값 push, () --> 2, [] --> 3
		// 2) 스택 두 번째 위에 여는 괄호가 있는 경우 (맨 위에는 값이 존재)
				//2.1) 스택 맨 위에 값과 두 번째 위에 있는 여는 괄호 모두 pop
				//2.2) 스택에 값 push, (x) --> 2X, [X] --> 3X
		// 3) 스택의 맨 위 둘 다 값이라면, 합친다.
		
		{
			if (myStack[myTop - 1] == -1 ||
				myStack[myTop - 1] == -2) // 스택 맨 위가 여는 괄호라면
			{
				if (paren[i] == ')' && myStack[myTop - 1] == -1)  // () 짝이 맞다면
				{
					
					// 질문
					//// [--myTop] or [++myTop] 차이
						
					myStack[--myTop] = 0;
					myStack[myTop++] = 2;
				}
				else if (paren[i] == ']' && myStack[myTop - 1] == -2)
				{
					myStack[--myTop] = 0;
					myStack[myTop++] = 3;					
				}
				else
				// 짝이 맞지 않는다면
				// [), (]  --> 입력이 올바르지 않다면
				{
					printf("0\n");
					return 0;
				}
			}
			else 
			{
				//스택이 아예 비어 있다면
				if (myTop == 0)
				{
					printf("0\n");
					return 0;
				}
			
				int myValue = myStack[myTop - 1];
				myStack[--myTop] = 0; // 값 pop
				
				if (paren[i] == ')' && myStack[myTop - 1] == -1) 
				{
					myStack[--myTop] = 0;
					myStack[myTop++] = 2 * myValue;
				}
				else if (paren[i] == ']' && myStack[myTop - 1] == -2)
				{
					myStack[--myTop] = 0;
					myStack[myTop++] = 3 * myValue;
				}
				else
				{
					printf("0\n");
					return 0;				
				}
			}
			
			// 맨 위에는 값이 있지만 그 다음은 값이 없을 수도 있으니(myTop >= 2)				
				// 이제 값이 나올텐데 그 다음도 값일 수 있으니 합쳐주는 작업
			if (myTop >= 2 && myStack[myTop - 1] > 0 && myStack[myTop - 2] > 0)
			{
				myStack[myTop - 2] += myStack[myTop - 1];
				myStack[--myTop] = 0;
			}
									
		}
	}
	
	if (myTop == 1 && myStack[0] > 0) printf("%d\n", myStack[0]);
	else printf("0\n");
	
	return 0;
	
}