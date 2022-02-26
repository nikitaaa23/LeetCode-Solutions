class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int t[n];
    
        for(int i = 0; i<n; i++){
            t[i] = 1;
        }
        
        for(int i = 1; i<n; i++){
            for(int j = 0;j<i; j++){
                if(nums[i]>nums[j]){
                    t[i] = max(t[j]+1, t[i]);
                }
                
            }
        }
        return *max_element(t, t+n);
    }
};