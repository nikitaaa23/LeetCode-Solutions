class Solution {
public:
     
    bool isValid(int mid, int n, int m, vector<int>nums){
        int ele = 1;
        int sum = 0;
       for(int i = 0; i<n; i++){
            sum+=nums[i];
            
            if(sum>mid){
                ele++;
                sum = nums[i];
            }
            if(ele>m)
                return false;
        }
        return true;
    }
    int splitArray(vector<int>& nums, int m) {
      
        int mx = 0, sum= 0;
        int n = nums.size();
        for(int i = 0; i<nums.size(); i++){
            sum+=nums[i];
            mx = max(mx, nums[i]);
        }
        int res = 0;
        
        int l = mx, r = sum;
        
        while(l<=r){
            int mid = l+(r-l)/2;
            
            if(isValid(mid, n, m, nums)){
                res = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return res;
    }
};