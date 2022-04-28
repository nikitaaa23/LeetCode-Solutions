class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        
       vector<vector<int>> effort(n, vector<int>(m, INT_MAX));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,  greater<pair<int, pair<int, int>>>> pq;
        
        pq.push({0,{0, 0}});
        
         vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while(!pq.empty()) {
            pair<int, pair<int, int>> min = pq.top();
            pq.pop();
            
            int dist = min.first, row = min.second.first, col = min.second.second;
            if(dist > effort[row][col])
                continue;
            
            if(row == n - 1 && col == m - 1)
                return dist;
            
            for(vector<int> d : dir) {
                int newRow = row + d[0];
                int newCol = col + d[1];
                
                if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m) {
                    int newDist = max(dist, abs(heights[newRow][newCol] - heights[row][col]));
                    if(newDist < effort[newRow][newCol]) {
                        effort[newRow][newCol] = newDist;
                        pq.push({newDist, {newRow, newCol}});
                    }
                }
            }
        }
        return 0;
    }
};

// 1, 2, 3, 5, 6 
// 