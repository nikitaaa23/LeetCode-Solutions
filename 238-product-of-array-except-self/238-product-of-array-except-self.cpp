class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int l[n], r[n];
        l[0] = 1;
        r[n-1] = 1;
        for(int i = 1; i<n; i++){
            l[i] = nums[i-1]*l[i-1];
        }
        
         for(int i = n-2; i>=0; i--){
           r[i] = nums[i+1]*r[i+1];
        }
        
        vector<int>ans(n);
        
        for(int i=0; i<n; i++){
            ans[i] = l[i]*r[i];
        }
            
        return ans;
    }
};
// 1 1 2 6
//  24  12  4   1