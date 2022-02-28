class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n =  nums.size();
        vector<string>ans;
        if(nums.size()==0){
            return {};
        }
        string s = to_string(nums[0]);
        int start = nums[0];
        for(int i = 1; i<nums.size(); i++){
            if(nums[i] == (1 + nums[i-1])){
                continue;
            }
            if(start !=nums[i-1]){
                 s+="->" + to_string(nums[i-1]);
            }
            ans.push_back(s);
            s=to_string(nums[i]);
            start = nums[i];
        }
         if(start != nums[n-1]){s += "->"+to_string(nums[n-1]);}
        ans.push_back(s);
        return ans;
    }
};