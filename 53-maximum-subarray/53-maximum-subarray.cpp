class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        int currsum = nums[0];
        int mx = nums[0];
        
        for(int i = 1; i<nums.size(); i++){
             currsum = max(currsum+nums[i], nums[i]);
            mx = max(mx, currsum);
           
        }
        return mx;
    }
};