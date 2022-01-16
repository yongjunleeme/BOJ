#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int a[10005] = {0,};
	
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
	    int k;
	    cin >> k;
	    a[k]++;
	}
	
	for (int i = 1; i <= 10000; i++)
	    for (int j = 0; j < a[i]; j++)
	        cout << i << "\n";
}