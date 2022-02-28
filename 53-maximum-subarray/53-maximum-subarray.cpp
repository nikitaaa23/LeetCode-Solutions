class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currsum = 0, maxsum = INT_MIN;
        
        for(int i = 0 ;i<nums.size(); i++){
            currsum = max(currsum+nums[i], nums[i]);
            maxsum = max(currsum, maxsum);
        }
        
        return maxsum;
    }
};