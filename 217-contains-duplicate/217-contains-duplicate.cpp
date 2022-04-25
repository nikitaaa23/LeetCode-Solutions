class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int>s;
        for(auto x : nums){
            if(s.find(x)==s.end()){
                s.insert(x);
            }
            else
                return true;
        }
        return false;
    }
};