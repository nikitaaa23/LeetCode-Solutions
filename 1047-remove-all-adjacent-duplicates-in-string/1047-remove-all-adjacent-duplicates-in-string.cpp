class Solution {
public:
    string removeDuplicates(string s) {
        string t;
        int i=0;
        while(i<s.length()){
            if(t.empty() || s[i]!=t.back()){
                t.push_back(s[i]);
                i++;
            }
            else{
                t.pop_back();
                i++;
            }
        }
        return t;
    }
};