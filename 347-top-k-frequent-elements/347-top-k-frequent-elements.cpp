class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int>mp;
        vector<int>ans;
        priority_queue<pair<int, int>>pq;
        
        for(int i = 0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        for(auto x : mp){
            pq.push({x.second, x.first});
        }
        
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};