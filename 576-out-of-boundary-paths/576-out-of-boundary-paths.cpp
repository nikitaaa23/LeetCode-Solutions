class Solution {
public:
    
    #define mod 1000000007
    long long int dp[55][55][55];
    
    long long int solve(int m, int n, int maxMove, int startRow, int startColumn){
         if(startRow>=m || startRow <0 ||startColumn>=n || startColumn<0){
            return 1;
        } 
        
        if(maxMove==0){
            return 0;
        }
        
        
        if(dp[startRow][startColumn][maxMove]!=-1){
            return dp[startRow][startColumn][maxMove];
        }
        
        long long int total =0;
        long long int l = solve(m, n, maxMove-1, startRow-1, startColumn);
        long long int r = solve(m, n, maxMove-1, startRow+1, startColumn);
        long long int t = solve(m, n, maxMove-1, startRow, startColumn-1);
        long long int b = solve(m, n, maxMove-1, startRow, startColumn+1);
        return dp[startRow][startColumn][maxMove] = ((l%mod) + (r%mod) + (t%mod) + (b%mod))%mod;
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        
        
        memset(dp, -1, sizeof(dp));
        
       return solve(m, n, maxMove, startRow,startColumn)%mod;
    }
};