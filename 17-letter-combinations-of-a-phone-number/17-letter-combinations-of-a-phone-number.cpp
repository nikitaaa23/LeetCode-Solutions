class Solution {
public:
     vector<string>ans;
    
    void solve(string digits, string s, unordered_map<int, string>&mp, int i){
        if(s.size()==digits.size()){
            reverse(s.begin(), s.end());
            ans.push_back(s);
            return;
        }
        
        string t = mp.at(digits[i]);
        
        for(int j=0; j<t.size(); j++){
            s.push_back(t[j]);
            solve(digits, s, mp, i-1);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        if(n==0)
            return {};
        string s;
         unordered_map<int, string>mp;
        mp['2'] = {"abc"};
        mp['3'] = {"def"};
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        
        solve(digits, s, mp, n-1);
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};