class Solution {
public:
    
    int solve(int n, int dp[]){
        if(n==0 || n==1)
            return 1;
        if(dp[n]!=0){
            return dp[n];
        }
        dp[n] = solve(n-1, dp) + solve(n-2, dp);
        return dp[n];
    }
    int climbStairs(int n) {
        int dp[n+1];
        memset(dp, 0, sizeof(dp));
        return solve(n, dp);
    }
};