class Solution {
public:
    
    bool bfs(int i, int col[], vector<vector<int>>& graph){
        queue<int>q;
        q.push(i);
        col[i] = 0;
        while(!q.empty()){
            auto t = q.front();
            q.pop();
            
            for(auto x : graph[t]){
                if(col[x]==-1){
                    q.push(x);
                    col[x] = 1-col[t];
                }
                else if(col[x] == col[t])
                    return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        int col[n];
        memset(col, -1, sizeof(col));
        
        for(int i = 0; i<n; i++){
            if(col[i] == -1){
                if (!bfs(i, col, graph))
                    return false;
            }
        }
        return true;
    }
};