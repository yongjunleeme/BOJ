class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cnt = 0;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == nums[i-1]) cnt++;
            else nums[i - cnt] = nums[i];
        }
        return nums.size() - cnt;
    }
};