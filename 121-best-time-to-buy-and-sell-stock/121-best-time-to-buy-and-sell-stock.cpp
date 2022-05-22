class Solution {
public:
   
    int maxProfit(vector<int>& prices) {
//          int n = prices.size();
//          int p = INT_MAX;
//         int mx = 0;
        
//         for(int i = 0; i<n; i++){
//             p = min(prices[i], p);
//             mx = max(prices[i]-p, mx);
//         }
//         return mx;
        //  int n = prices.size(), mx = 0;
        // for(int i=0;i<n;i++){
        //     for(int j=i+1; j<n;j++){
        //         if(prices[i] < prices[j]){
        //             mx = max(prices[j] - prices[i], mx);
        //         }
        //     }
        // }
        // return mx;
        
        int n = prices.size();
        int mn = prices[0], profit = 0;
        
        for(int i = 0; i<n; i++){
            if(mn > prices[i]){
                mn = prices[i];
            }
            if(prices[i] - mn > profit){
                profit = prices[i]- mn;
            }
        }
        return profit;
    }
};