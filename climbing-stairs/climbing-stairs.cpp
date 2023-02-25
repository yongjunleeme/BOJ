class Solution {
public:
    int climbStairs(int n) {
        int d[50];
        d[1] = 1;
        d[2] = 2;
        d[3] = 3;
        d[4] = 5;
        for(int i = 5; i <= n; i++){
            d[i] = d[i-1] + d[i-2];
        }
        return d[n];        
    }
};