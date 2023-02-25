class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int d[100005];
        fill(d, d+10005, 0);
        for(int i = 1; i < prices.size(); i++){
            d[i] = max(d[i-1] + prices[i] - prices[i-1], 0);
        }
        return *max_element(d, d+10005);
        
    }
};