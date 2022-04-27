class Solution {
public:
    
    bool vis[100001];
    vector<int>adj[100001];
    void dfs(string &s, int i, vector<char>&chars,vector<int>&idx){
        chars.push_back(s[i]);
        idx.push_back(i);
        vis[i] = true;
        
        for(auto x: adj[i]){
            if(!vis[x])
                dfs(s, x, chars, idx);
        }
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        
        
        for(auto x : pairs){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
       
        for(int i = 0; i<n; i++){
            if(!vis[i]){
                vector<char>chars;
                vector<int>idx;
                
                dfs(s, i, chars, idx);
                sort(chars.begin(), chars.end());
                sort(idx.begin(), idx.end());
                
                for(int j = 0; j<chars.size(); j++){
                    s[idx[j]] = chars[j];
                }
            }
        }
        return s;
    }
};