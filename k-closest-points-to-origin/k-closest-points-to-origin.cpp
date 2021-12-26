class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>>res(k);
        priority_queue<vector<int>>pq;
        
        for(auto &p : points){
            int x = p[0], y = p[1];
            pq.push({x*x+y*y, x, y});
            if(pq.size()>k)
                pq.pop();
        }
        
        for(int i =0; i<k; i++){
            auto tp = pq.top();
            pq.pop();
            res[i] = {tp[1], tp[2]};
        }
        return res;
    }
};