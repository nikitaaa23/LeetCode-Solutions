class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string>mp;
        int required= 1<<k;
        for(int i=0;i+k-1<s.size();i++)
        {
            if(mp.find(s.substr(i,k))==mp.end())
                mp.insert(s.substr(i,k));
            if(mp.size()==pow(2,k))
                return true;
        }
        return false;
    }
};