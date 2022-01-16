#include <bits/stdc++.h>
using namespace std;

struct p
{
    int age;
    string name;
};

p arr[1000005];
p temp[1000005];

void merge(int start, int end)
{
    int mid = (start + end) / 2;
    int lidx = start;
    int ridx = mid;
    
    for (int i = start; i < end; i++)
    {
        if (lidx == mid) 
        {
            temp[i].age = arr[ridx].age;
            temp[i].name = arr[ridx].name;
            ridx++;
        }
        else if (ridx == end)
        {
            temp[i].age = arr[lidx].age;
            temp[i].name = arr[lidx].name;
            lidx++;
        }
        else if (arr[lidx].age <= arr[ridx].age)
        {
            temp[i].age = arr[lidx].age;
            temp[i].name = arr[lidx].name;
            lidx++;
        }
        else
        {
            temp[i].age = arr[ridx].age;
            temp[i].name = arr[ridx].name;
            ridx++;
        }
        
    }
    for (int i = start; i < end; i++)
    {
        arr[i].age = temp[i].age;
        arr[i].name = temp[i].name;
    }
        
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
    
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].age >> arr[i].name;
    }
    
    mergeSort(0, n);
    
    for (int i = 0; i < n; i++) cout << arr[i].age << " " << arr[i].name << "\n"; 
}