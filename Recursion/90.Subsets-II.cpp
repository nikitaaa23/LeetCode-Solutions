class Solution {
public:
    vector<int>temp;
    vector<vector<int>>ans;
    set<vector<int>>s;
    void solve(vector<int>& nums, int index, int n){
        s.insert(temp);
              
        for (int i = index; i < nums.size(); i++) {
            temp.push_back(nums[i]);
            solve(nums, i + 1, n);
            temp.pop_back();
        }         
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        solve(nums, 0, n);
        
        for(auto x : s){
            ans.push_back(x);
        }
        return ans;
    }
};