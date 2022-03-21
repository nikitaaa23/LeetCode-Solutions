class Solution {
public:
//    int plan(vector<int>& nums)
// {
//     int n=nums.size();
    
//     vector<int> dp(n+1,0);
//     dp[1]=nums[0];
    
//     for(int i=2;i<=n;i++)
//     {
//         dp[i]=max(dp[i-2]+nums[i-1],dp[i-1]);
//     }
    
//     return dp[n];
// }
    int houseRob(vector<int>& nums,int i,int j){
	
        int profit1 = nums[i];
        int profit2 = max(nums[i],nums[i+1]);
	
        if(j-i==1) return profit2;
        int profit3;
		
        for(int k=i+2;k<j;k++){
            profit3 = max(profit1 + nums[k], profit2);
            profit1 = profit2;
            profit2 = profit3;
        }
        return profit3;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
    
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
		
        return max(houseRob(nums,0,n-1),houseRob(nums,1,n));
    }
};