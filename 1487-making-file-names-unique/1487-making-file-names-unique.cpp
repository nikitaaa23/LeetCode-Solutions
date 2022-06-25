class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        unordered_map<string, int>mp;
         vector<string>ans;
        for(auto x : names){
            if(mp.find(x)!=mp.end()){
                int y = mp[x];
                string new_str = x + "(" + to_string(y) + ")";
                while(mp.find(new_str)!=mp.end()){
                    mp[x]++;
                    new_str = x + "(" + to_string(mp[x]) + ")";
                   
                }
                 mp[new_str]++;
                ans.push_back( x + "(" + to_string(mp[x]) + ")");
            }
            else{
                ans.push_back(x);
                mp[x]++;
            }
        }
        return ans;
    }
};