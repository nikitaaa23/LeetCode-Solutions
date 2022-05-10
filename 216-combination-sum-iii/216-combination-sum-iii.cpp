class Solution {
public:
    vector<vector<int>>ans;
    
    void solve(int k, int n, int i, vector<int>temp){
        if(k==0 && n==0){
        ans.push_back(temp);
        return;
    }
    
    for(int j=i; j<=9 ; j++){
        
        
        temp.push_back(j);
        solve(k-1, n-j, j+1, temp);
        temp.pop_back();
        
    }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
         vector<int> temp;
    solve(k, n, 1, temp);
    return ans;
    }
};