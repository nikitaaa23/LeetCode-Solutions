class Solution {
public:
    vector<vector<int>>ans;
    vector<int>temp;
    void solve(vector<int>& nums, int n, int i){
        ans.push_back(temp);
        
        for(int j =i; j<n; j++){
            temp.push_back(nums[j]);
            solve(nums, n, j+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        solve(nums, n, 0);
        return ans;
    }
};