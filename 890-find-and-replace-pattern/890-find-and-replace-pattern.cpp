class Solution {
public:
    bool match(string &word, string &pattern){
         unordered_map<char, char>mp1, mp2;
         for(int i = 0; i<word.size(); i++){
             char c = word[i];
             char d = pattern[i];
             if(mp1.find(c)==mp1.end()){
                 mp1[c] = d;
             }
             if(mp2.find(d)==mp2.end()){
                 mp2[d] = c;
             }
             if(mp1[c]!=d || mp2[d]!=c){
                 return false;
             }
        }
        return true;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
       
        vector<string>ans;
        for(auto x : words){
            if(match(x, pattern))
                ans.push_back(x);
        }       
        return ans;
    }
};