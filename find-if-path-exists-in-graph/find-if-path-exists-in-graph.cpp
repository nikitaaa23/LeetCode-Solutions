class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>adj(n, vector<int>());
        
        for(auto x: edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        
        queue<int>q;
        vector<int>vis(200000, 0);
        q.push(source);
        vis[source] = 1;
        
        while(!q.empty()){
            auto t = q.front();
            q.pop();
            if(t==destination){
                    return true;
            }
            for(auto x: adj[t]){
                if(!vis[x]){
                    vis[x] = 1;
                    q.push(x);
                }
            }
            
        }
        return false;
    }
};