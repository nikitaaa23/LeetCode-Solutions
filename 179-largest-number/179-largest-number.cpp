class Solution {
public:
    
    static bool cmp(string n1, string n2){
        return (n1+n2) > (n2+n1);
    }
    string largestNumber(vector<int>& num2) {
        int n = num2.size();
        vector<string>nums;
        for(int i = 0; i<n; i++){
            nums.push_back(to_string(num2[i]));
        }
        sort(nums.begin(), nums.end(), cmp);
        
        if(nums[0] == "0")
            return "0";
        
        string ans = "";
        
        for(auto x : nums){
            ans+=x;
        }
        
        return ans;
    }
};