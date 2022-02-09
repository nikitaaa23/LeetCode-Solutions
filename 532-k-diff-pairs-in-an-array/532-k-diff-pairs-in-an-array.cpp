class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int i = 0, j = 1, n=nums.size();
        int ans = 0;
        while(j<n && i<n-1){
            if(i==j) j++;
            int diff = abs(nums[i] - nums[j]);
            
            if(diff == k){
                ans++;
                while(j<n-1 && nums[j]==nums[j+1])
                    j++;
                j++;
            }
            else if(diff<k){
                j++;
            }
            else i++;
        }
        return ans;
    }
};