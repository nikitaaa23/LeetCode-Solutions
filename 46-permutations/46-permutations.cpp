class Solution {
public:
    
    vector<vector<int>>ans;
   void backtrack(int i, int n, vector<int>& nums){
       
       if(i==n){
            ans.push_back(nums);
           return;
       }
      
       for(int j= i; j<n; j++){
      swap(nums[i], nums[j]);
           backtrack(i+1, n, nums);
       swap(nums[i], nums[j]);
       }
   }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        backtrack(0, n, nums);
        return ans;
    }
};