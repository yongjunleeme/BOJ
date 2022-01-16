#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	queue <int> Q;
	int n;
	cin >> n;
	
	for (int i = 1; i <= n; i++) Q.push(i);
	
	while (Q.size() != 1)
	{
    	Q.pop();
    	int a = Q.front();
    	Q.push(a);
    	Q.pop();
	}
	
	cout << Q.front();
}
