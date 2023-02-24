class Solution {
public:
    
    int singleNumber(vector<int>& nums) {
        int a[60005];
        fill(a, a+60005, 0);
        for(int i = 0; i < nums.size(); i++)
            a[nums[i] + 30000]++;
        for(int i = 0; i < 60000; i++){
            if(a[i] == 1) return i - 30000;
        }
        return 0;
    }
};