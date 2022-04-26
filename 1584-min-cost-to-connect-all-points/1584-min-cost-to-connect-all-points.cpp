class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<bool>vis(n);
        
        pq.push({0, 0});
        int mst = 0;
        int used = 0;
        
        while(used < n){
            auto t = pq.top();
            pq.pop();
            int wt = t.first;
            int curr = t.second;
            
            if(vis[curr])
                continue;
            
            vis[curr] = true;
            mst+=wt;
            used++;
            
           for(int i = 1; i<n; i++){
               pq.push({abs(points[curr][0]-points[i][0]) + abs(points[curr][1]-points[i][1]), i});
           }
        }
        return mst;
    }
};