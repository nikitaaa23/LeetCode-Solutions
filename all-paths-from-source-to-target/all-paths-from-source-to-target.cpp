class Solution {
public:
    
    vector<vector<int>>ans;
    
    void dfs(vector<vector<int>>& graph, int i, vector<int>& path){
        path.push_back(i);
        if(i==graph.size()-1){
            ans.push_back(path);
            return;
        }
        
        for(int j = 0; j<graph[i].size(); j++){
            dfs(graph, graph[i][j], path);
            path.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int>path;
        dfs(graph, 0, path);
        
        return ans;
    }
};