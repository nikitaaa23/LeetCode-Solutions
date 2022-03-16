class Solution {
public:
    bool isPalindrome(string s) {
        //s.erase(remove(s.begin(), s.end(), ' '), s.end());
       // s.erase(remove(s.begin(), s.end(), ','), s.end());
        
       // cout<<s;
        string t = "";
        for(char c: s){
            if(c>='A' && c<='Z')
                t+= (char) c+32;
            else if(c>='A' && c<='Z' || (c>='a' && c<='z') || (c>='0' && c<='9'))
                t+=c;
        }
        
        string p = t;
        
        reverse(t.begin(), t.end());
        if(p==t)
        return true;
        
        return false;
    }
};