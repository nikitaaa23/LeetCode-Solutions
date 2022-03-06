class Solution {
public:
    int mod = 1e9+7;
    vector<vector<int>>dp;
    
    long total(int unp, int und){
        if(unp==0 && und==0){
            return 1;
        }
        
        if(unp<0 || und<0 || und<unp){
            return 0;
        }
        
        
        if(dp[unp][und]){
            return dp[unp][und];
        }
        long ans =0;
        ans+=unp * total(unp-1, und);
        ans%=mod;
        ans+= (und-unp ) * total(unp, und-1);
        ans%=mod;
        
        return dp[unp][und] = ans;
    } 
    
    int countOrders(int n) {
        dp = vector<vector<int>>(n+1, vector<int>(n+1, 0));
        return total(n, n);
    }
};