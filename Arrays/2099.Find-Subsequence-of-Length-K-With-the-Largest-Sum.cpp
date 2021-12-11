class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, int>mp;
        
        vector<int>ans;
        
        for(int i = 0; i<n; i++){
            ans.push_back(nums[i]);
        }
    
        sort(ans.begin(), ans.end());
        ans.erase(ans.begin()+(n-k), ans.end());
        
        for(auto x : ans){
            mp[x]++;
        }
        vector<int>v;
        for(auto x : nums){
            if(mp.find(x)!=mp.end()){
                mp[x]--;
                if(mp[x]==0) mp.erase(x);
            }
            else
                v.push_back(x);
        }
        return v;
    }
};