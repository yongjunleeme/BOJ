#include <bits/stdc++.h>
using namespace std;

#define ll long long

stack <int> s;
int n;
ll ans;
	
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;	
	ll h;
	
	while (n--)
	{
		cin >> h;
		while (!s.empty() && s.top() <= h)
			s.pop();
		ans += s.size();
		s.push(h);
	}
	
	cout << ans;	
}