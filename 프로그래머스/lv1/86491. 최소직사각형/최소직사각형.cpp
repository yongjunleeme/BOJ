#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> sizes) {
    int x = 0, y = 0;
    for(int i = 0; i < sizes.size(); i++){
        x = max(x, max(sizes[i][0], sizes[i][1]));
        y = max(y, min(sizes[i][0], sizes[i][1]));        
    }
    
    return x * y;
}