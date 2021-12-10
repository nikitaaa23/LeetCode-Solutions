class Solution {
public:
    vector<vector<int>>ans;
    vector<int>t;
    
    void solve(vector<int>& candidates, int target, int n, int idx){
        if(target==0){
            ans.push_back(t);
        }
        
        if(target<0) return;
        
        for(int i = idx; i<n; i++){
            if(i>idx && candidates[i]==candidates[i-1]) continue;
            t.push_back(candidates[i]);
            solve(candidates, target-candidates[i], n, i+1);
            t.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        sort(candidates.begin(), candidates.end());
        solve(candidates, target, n, 0);
        
        return ans;
    }
};