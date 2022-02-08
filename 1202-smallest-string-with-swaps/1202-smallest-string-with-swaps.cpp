class Solution {
public:
    
    void dfs( vector<vector<int>>&adj, vector<int>&path, vector<int>&vis, int st){
        path.push_back(st);
        vis[st] = true;
        for(auto x: adj[st]){
            if(!vis[x]){
                dfs(adj, path, vis, x);
            }
        }
    }
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        vector<vector<int>>adj(s.size());
        
        for(auto x : pairs){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        
        vector<int>vis(n, 0);
        
        for(int i = 0; i<n; i++){
           
            if(!vis[i]){
                vector<int>path;
                dfs(adj, path, vis, i);
                
                string t ="";
                for(auto x: path){
                    t+=s[x];
                }
                sort(path.begin(), path.end());
                sort(t.begin(), t.end());
                int j = 0;
                
                for(auto x: path){
                    s[x]=t[j];
                    j++;
                }
            }
        }
        return s;
    }
};