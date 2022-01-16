#include <bits/stdc++.h>
using namespace std;

int n, k;
stack<pair<int, int>> S;
	
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	S.push({100000001, 0});
	for (int i = 1; i <= n; i++)
	{
		cin >> k;
		
		while (S.top().first < k)
		    S.pop();
		    
		cout << S.top().second << " ";
		S.push({k, i});
	}
}