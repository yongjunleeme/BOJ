#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> nums)
{    
    int answer = 0;
    map<int, int> m;
    for(int i = 0; i < nums.size(); i++){
        m[nums[i]]++;
    }
    int halfSize = floor(nums.size() / 2);
    int mSize = m.size();
    answer = min(halfSize, mSize);
    

    return answer;    
}