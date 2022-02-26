class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
         int n = graph.size();
    int finalMask = (1 << n) - 1;
    queue<pair<int,pair<int,int>>>q;
    set<pair<int,int>>vis;
    for (int i = 0 ; i < n ; i++)
    {
        int mask = (1 << i);
        q.push({i , {0 , mask}});
        vis.insert({i , mask});
    }
    while(!q.empty())
    {
        auto node = q.front();
        q.pop();
        int val = node.first;
        int dis = node.second.first;
        int mask = node.second.second;
        for (auto it : graph[val])
        {
            int newMask = (mask | 1<<it);
            if(newMask == finalMask) return dis+1;
            else if(vis.count({it , newMask})) continue;
            vis.insert({it , newMask});
            q.push({it , {dis+1 , newMask}});
        }
    }
    return 0;
    }
};