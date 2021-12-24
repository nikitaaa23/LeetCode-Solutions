class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>>v;
        v.push_back(intervals[0]);
        
        for(int i = 1; i<intervals.size(); i++){
            if(intervals[i][0]<=v.back()[1])
                v.back()[1] = max(intervals[i][1], v.back()[1]);
            else
                v.push_back(intervals[i]);                
        }
        return v;
    }
};