class Solution {
public:
    
    vector<string>ans;
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>>mp;
    
    void dfs(string src){
       
        while(!mp[src].empty()){
            auto t = mp[src].top();
            mp[src].pop();
            dfs(t);
        }
         ans.push_back(src);
        return;
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        int n = tickets.size();
        for(auto x : tickets){
            mp[x[0]].push(x[1]);
        }
        
        string src ="JFK";
        
        dfs(src);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};