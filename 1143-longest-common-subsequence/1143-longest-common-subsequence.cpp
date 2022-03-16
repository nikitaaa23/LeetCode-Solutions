class Solution {
public:
    int t[1001][1001];
    int solve(string &text1, string &text2, int n, int m){
        if(n==0 || m==0)
            return 0;
        if(t[n][m]!=0)
            return t[n][m];
        
        if(text1[n-1]==text2[m-1])
            return t[n][m] = 1 + solve(text1, text2, n-1, m-1);
        else
            return t[n][m] = max(solve(text1, text2, n-1, m), solve(text1, text2, n, m-1) );
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n =text1.size();
        int m = text2.size();
        memset(t, 0, sizeof(t));
//         int t[n+1][m+1];
        
//         memset(t, -1, sizeof(t));
        
//         for(int i = 0; i<=n; i++){
//             for(int j = 0; j<=m; j++){
//                 if(i==0 || j==0)
//                     t[i][j] = 0;
//             }
//         }
        
//         for(int i = 1; i<=n; i++){
//             for(int j = 1; j<=m; j++){
//                 if(text1[i-1]==text2[j-1])
//                     t[i][j] = 1+ t[i-1][j-1];
//                 else
//                     t[i][j] = max(t[i][j-1], t[i-1][j]);
//             }
//         }
        return solve(text1, text2, n, m);
    }
    
};