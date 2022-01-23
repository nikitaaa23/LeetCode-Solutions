class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==1) return 0;
        int l = 0, r = nums.size();
        
        while(l<=r){
            int mid = l +(r-l)/2;
            if(mid>0 && mid<nums.size()-1){
                if(nums[mid]>nums[mid+1] && nums[mid-1]<nums[mid])
                    return mid;
                else if(nums[mid]<nums[mid+1])
                    l = mid+1;
                else
                    r = mid-1;
            }
            else if(mid==0){
                if(nums[mid]>nums[mid+1])
                return 0;
                else return 1;
            }
            else if(mid==nums.size()-1){
                if(nums[mid-1]<nums[mid])
                return nums.size()-1;
                else return nums.size()-2;
            }
        }
        return 0;
    }
};