class Solution {
public:
    
    int first(vector<int>& nums, int target){
        int l = 0, h = nums.size()-1;
        int res = -1;
        while(l<=h){
            int mid = l + (h-l)/2;
            if(target==nums[mid]){
                res = mid;
                h = mid-1;
            }
            else if(target>nums[mid]){
                l = mid+1;
            }
            else{
                h = mid-1;
            }
        }
        return res;
    }
    
    int last(vector<int>& nums, int target){
        int l = 0, h = nums.size()-1;
        int res = -1;
        while(l<=h){
            int mid = l + (h-l)/2;
            if(target==nums[mid]){
                res = mid;
                l = mid+1;
            }
            else if(target>nums[mid]){
                l = mid+1;
            }
            else{
               h = mid-1;
            }
        }
        return res;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int x = first(nums, target);
        int y = last(nums, target);
        return {x, y};
    }
};