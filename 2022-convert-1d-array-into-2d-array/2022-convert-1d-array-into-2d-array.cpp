class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>>ans(m, vector<int>(n));
        int p = original.size();
        if(m*n != p)
            return {};
        
        int k=0;
        for(int i =0;i<m; i++){
            for(int j=0;j<n; j++){
                if(k<p){
                ans[i][j] = original[k];
                k++;
                }
            }
        }
        return ans;
    }
};