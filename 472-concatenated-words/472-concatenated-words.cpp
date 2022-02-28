class Solution {
public:
    
   unordered_set<string> tmp;
    
    bool canform(string &word, unordered_set<string>&s){
        if(tmp.count(word))
            return true;
        for(int i = 1; i<word.size(); i++){
            string l = word.substr(0, i);
            string r = word.substr(i);
            
            if(s.count(l)){
                if(s.count(r) || canform(r, s)){
                    tmp.insert(word);
                    return true;
                }
            }
        }
        return false;
    }
    
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string>s(words.begin(),words.end());
        vector<string>ans;
        if(words.size()<=1)
            return ans;
        for(int i=0;i<words.size();i++)
        {
            if(canform(words[i],s))
                ans.push_back(words[i]);
        }
        return ans;
    }
};