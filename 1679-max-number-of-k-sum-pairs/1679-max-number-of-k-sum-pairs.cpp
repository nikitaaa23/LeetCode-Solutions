class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int count =0, n =nums.size();
        sort(nums.begin(), nums.end());
        int i=0, j=n-1;
        
        while(i<j){
            if(nums[i]+nums[j]==k){
                i++; j--;
                count++;
            }
            else if(nums[i]+nums[j]<k){
                i++; 
            }
            else{
                j--;
            }
        }
        return count;
    }
};