class Solution {
public:
    vector<vector<int>>ans;
    vector<int>temp;

    void solve(vector<int>& candidates, int target, int n, int idx){
        if(target==0){
            ans.push_back(temp);
        }
        if(target<0) return;
        for(int i= idx; i<n; i++){
            temp.push_back(candidates[i]);
            solve(candidates, target-candidates[i], n, i);
            temp.pop_back();
        }        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        solve(candidates, target, n, 0);
        return ans;
    }
};