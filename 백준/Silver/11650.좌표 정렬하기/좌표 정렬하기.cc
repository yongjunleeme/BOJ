#include <bits/stdc++.h>
using namespace std;


int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector <pair<long, long>> arr;
    pair<long, long> temp;
    
    for (int i = 0; i < n; i++)
    {
        cin >> temp.first >> temp.second;
        arr.push_back(temp);
    }
    
    sort(arr.begin(), arr.end());
    
    for (int i = 0; i < n; i++)
        cout << arr[i].first << " " << arr[i].second << "\n";
    
}