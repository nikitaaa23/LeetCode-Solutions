class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1) return vector<int>{0};
        
        vector<int>in(n,0);
        vector<vector<int>>g(n);
        for(int i = 0; i<edges.size(); i++){
            int a = edges[i][0];
            int b = edges[i][1];
            in[a]++;
            in[b]++;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        queue<int>q;
        for(int i =0;i<n;i++){
            if(in[i]==1)
                q.push(i);
        }
        vector<int>ans;
        while(!q.empty()){
            int m = q.size();
            ans.clear();
            while(m--){
                int t = q.front();
                q.pop();
                ans.push_back(t);
                for(int i = 0;i<g[t].size(); i++){
                    in[g[t][i]]--;
                    if(in[g[t][i]]==1)
                        q.push(g[t][i]);
                }
            }
        }
        return ans;
    }
};