class Solution {
public:
    vector<int> partitionLabels(string s) {
        int mp[26];        
        int n = s.size();
        vector<int>v;  
        
        for(int i = 0; i<n; i++){
            mp[s[i]-'a']= i;            //last index of each char
        }
        int start = 0, end =0;
        for(int i = 0; i<n; i++){
            end = max(end, mp[s[i]-'a']);       //end ptr on last index of curr char
            if(i==end){                         
                v.push_back(end-start+1);       //one window added to vec
                start = end+1;
            }
        }
        return v;
    }
};