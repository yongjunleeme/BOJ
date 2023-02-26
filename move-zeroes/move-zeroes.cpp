class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int idx = 0;
        int cnt = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0) cnt++;
            else nums[idx++] = nums[i];
        }
        while(cnt--){
            nums[nums.size() - cnt - 1] = 0;
        }        
    }
};