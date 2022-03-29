class Solution {
public:
    int maxProduct(vector<int>& nums) {
       int n = nums.size();
        int curr = nums[0];
        if(n==1){
            return curr;
        }
        int mx = nums[0], mn = nums[0];
        for(int i = 1; i<n; i++){
           if(nums[i] < 0)
               swap(mx, mn);
            mx = max(nums[i]*mx, nums[i]); //6, 6, 
            mn = min(nums[i]*mn, nums[i]); // 1, -12
            
            curr = max(mx, curr);
        }
        return curr;
    }
};
// mx=6, mn = 2, 
// mx=6, mn = 