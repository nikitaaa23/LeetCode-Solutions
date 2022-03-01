class Solution {
public:
    vector<int> countBits(int n) {
        if(n==0) return {0};
        vector<int>dp(n+1, 0);
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2; i<=n ;i++){
            if(i%2==0){
                dp[i] = dp[i/2];
                
            }
            else
                dp[i] = dp[i/2] + 1;
        }
        return dp;
        
        // for(int i = 0; i<=n; i++){
        //     int num = i;
        //     int sum = 0;
        //     while(num!=0){
        //         sum+=num%2;
        //         num = num/2;
        //     }
        //     dp.push_back(sum);
        // }
        // return dp;
    }
};