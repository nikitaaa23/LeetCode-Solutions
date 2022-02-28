class Solution {
public:
   
    int maxProfit(vector<int>& prices) {
         int n = prices.size();
         int p = INT_MAX;
        int mx = 0;
        
        for(int i = 0; i<n; i++){
            p = min(prices[i], p);
            mx = max(prices[i]-p, mx);
        }
        return mx;
    }
};