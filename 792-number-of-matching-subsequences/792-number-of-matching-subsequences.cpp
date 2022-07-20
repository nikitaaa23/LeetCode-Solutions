class Solution {
public:
   bool solve(string s1, string s2)
{
    int n = s1.length(), m = s2.length();
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (s1[i] == s2[j])
            j++;
        i++;
    }
    return j == m;
}
    int numMatchingSubseq(string s, vector<string>& words) {
        int n = s.size();
        int count = 0;
        unordered_map<string, int>mp;
       for (auto x : words){
           mp[x]++;
       }
        
        for(auto x : mp){
            if(solve(s, x.first)){
                count+=x.second;
            }
        }
        return count;
    }
};