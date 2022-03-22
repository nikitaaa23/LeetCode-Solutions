class Solution {
public:
    vector<vector<int>>res;
    vector<int>v;
    void dfs(vector<int>& nums, unordered_map<int, int>&mp){
        if(v.size()==nums.size()){
            res.push_back(v);
            return;
        }
        
        for(auto n : mp){
            if(n.second > 0){
                v.push_back(n.first);
                mp[n.first]--;
                dfs(nums, mp);
                mp[n.first]++;
                v.pop_back();
                
            }
        }
       
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        unordered_map<int, int>mp;
        for(auto c : nums){
            mp[c]++;
        }
        dfs(nums, mp);
        return res;
    }
};