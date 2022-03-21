class Solution {
public:
    vector<vector<int>>res;
    vector<int>curr;
    
    void dfs(int i, int total, vector<int>& candidates, int target){
        if(total==target){
            res.push_back(curr);
            return;
        }
        if(i>=candidates.size() || total > target)
            return;
        
        curr.push_back(candidates[i]);
        dfs(i, total+candidates[i], candidates, target);
        curr.pop_back();
        dfs(i+1, total, candidates, target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(0, 0, candidates, target);
        return res;
    }
};