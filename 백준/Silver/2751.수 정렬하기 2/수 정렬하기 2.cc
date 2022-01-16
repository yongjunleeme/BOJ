#include <bits/stdc++.h>
using namespace std;

int arr[1000001];
int temp[1000001];

void merge(int start, int end)
{
	int mid = (start + end) / 2;
	int lidx = start;
	int ridx = mid;
	
	for (int i = start; i < end; i++)
	{
		if (lidx == mid) temp[i] = arr[ridx++];
		else if (ridx == end) temp[i] = arr[lidx++];
		else if (arr[lidx] <= arr[ridx]) temp[i] = arr[lidx++];
		else temp[i] = arr[ridx++];
	}
	for (int i = start; i < end; i++) arr[i] = temp[i];
}

void mergeSort(int start, int end)
{
	if (end - start == 1) return;
	
	int mid = (start + end) / 2;
	mergeSort(start, mid);
	mergeSort(mid, end);
	
	merge(start, end);	
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++) cin >> arr[i];
	mergeSort(0, n);
	
	for (int i = 0; i < n; i++) cout << arr[i] << "\n";	
}