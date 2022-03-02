class Solution {
public:
    int helper(string x, string y) {
        int m = x.size();
        int n = y.size();
        int dp[m+1][n+1];
        for(int i = 0; i<=m; i++)
        {
            dp[i][0]=0;
        }
        for(int i = 0; i<=n; i++)
        {
            dp[0][i]=0;
        }
        for(int i = 1; i<=m; i++){
            for(int j = 1; j<=n; j++){
                if(x[i-1]==y[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
    
    bool isSubsequence(string s, string t) {
       // int ans = helper(s, t);
       //  if(ans == s.size())
       //      return true;
       //  return false;
        
        int n = s.size(), m=t.size();
        
        int i = 0, j =0;
        while(i<n && j<m){
            if(s[i]==t[j]){
                i++; j++;
            }
            else
                j++;
        }
        if(i==n)return true;
        else
            return false;
    }
};