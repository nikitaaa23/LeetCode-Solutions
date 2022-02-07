class Solution {
public:
    
    vector<vector<int>>ans;
   
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int>path;
        if(graph.size()==0){
            return ans;
        }
        queue<vector<int>>q;
        path.push_back(0);
        q.push(path);
        
        while(!q.empty()){
            auto t = q.front();
            q.pop();
            
            int root = t.back();
            for(auto x : graph[root]){
                vector<int>temp(t.begin(), t.end());
                temp.push_back(x);
                if(x==graph.size()-1){
                    ans.push_back(temp);
                }
                else{
                    q.push(temp);
                }
            }
        }
        return ans;
    }
};