class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int a[1005];
        fill(a, a+1005, 0);
        vector<int> ans;
        for(int i = 0; i < nums1.size(); i++) a[nums1[i]]++;
        
        for(int i = 0; i < nums2.size(); i++){
            if(a[nums2[i]]){
                ans.push_back(nums2[i]);
                a[nums2[i]]--;
            }
        }
    
        return ans;
    }
};