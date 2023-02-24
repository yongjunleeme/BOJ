class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size() - (k % nums.size());
        vector <int> ans;
        for(int i = n; i < nums.size(); i++){
            ans.push_back(nums[i]);
        }
        for(int i = 0; i < n; i++){
            ans.push_back(nums[i]);
        }
        for(int i = 0; i < nums.size(); i++)
            nums[i] = ans[i];
        return;
        
    }
};