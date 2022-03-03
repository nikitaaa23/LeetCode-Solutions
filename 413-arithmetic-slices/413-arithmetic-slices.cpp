class Solution {
public:
    int sum = 0;
       
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n= nums.size();
        if(n<3)
            return 0;
        int count =0, diff = 0;
        for(int i =0 ;i<n-2; i++){
            diff = nums[i+1] - nums[i];
            for(int j = i+2; j<n; j++){
                if(nums[j] - nums[j-1] == diff){
                    count++;
                }
                else
                    break;
            }
        }
        
        return count;
    }
};