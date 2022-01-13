class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int count = 1;
        int curr = nums[0];
        int j=0;

        for(int i = 1; i<n; i++){
            if(nums[i]==curr){
                count++;
                if(count>2){
                    j++;
                }
            }   
            else {
                curr = nums[i];
                count = 1;
            }
            nums[i-j] = nums[i];
        }
        return n-j;
    }
};