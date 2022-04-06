class Solution {
public:
    int threeSumMulti(vector<int>& nums, int target) {
        int n = nums.size();
        map<int, int>mp;
        int count = 0;
       for(int i=0;i<n; i++){
           count = (count + mp[target - nums[i]])%1000000007;
           for(int j = 0; j<i; j++){
               mp[nums[i] + nums[j]]++;
           }
       }
        return count;
    }
};