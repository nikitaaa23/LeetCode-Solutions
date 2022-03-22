class Solution {
public:
    int dfs(int i, vector<int>&dp, string s){
       if(i>s.size()){
            return 0;
        }
        if(i==(s.size())){
            return 1;
        }
        if(s[i]=='0'){
            return 0;
        }
        
        if(dp[i]!=-1){
            return dp[i];
        }
        
        int res1 = 0, res2 = 0;
        
        res1 = dfs(i+1, dp, s);
        int num=10*(s[i]-'0')+(s[i+1]-'0');
        if(num<=26){
        res2=dfs(i+2,dp, s);
        }
        dp[i] = res1+res2;
        return res1+res2;
    }
    int numDecodings(string s) {
        int n = s.size();
        
        vector<int>dp(n, -1);
        
       int ans=dfs(0,dp, s);
        return ans;
        
    }
};