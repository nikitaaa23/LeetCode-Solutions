class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, int i, int m){
        for(int j = 0; j<m; j++){
            if(isConnected[i][j]==1){
                isConnected[i][j] = 0;
                isConnected[j][i] = 0;
                
                dfs(isConnected, j, m);
            }
        }
        
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int m = isConnected[0].size();
        
        int count =0;
        
        for(int i = 0; i<n; i++){
                if(isConnected[i][i]==1){
                   dfs(isConnected, i, m);
                       count++;
                }
        }
        return count;
    }
};