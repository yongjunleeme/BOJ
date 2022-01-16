#include <bits/stdc++.h>
using namespace std;

const int MX = 100002;
int n, k;
int arr[MX];
int dist[MX];
queue <int> Q;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	fill(dist, dist + MX, -1);
	
	dist[n] = 0;
	arr[n] = n;
	Q.push(n);
	
	while (!Q.empty()) {
		int cur = Q.front(); Q.pop();
		
		for (int nxt : {cur * 2, cur + 1, cur - 1}) {
			if (nxt < 0 || nxt >= MX || dist[nxt] != -1) continue;
			dist[nxt] = dist[cur] + 1;
			arr[nxt] = cur;
			Q.push(nxt);
		}
	}
	cout << dist[k] << "\n";
	deque<int> track = {k};
	while (track.front() != n)
	    track.push_front(arr[track.front()]);
	for (int nxt : track) cout << nxt << " ";
	
} 