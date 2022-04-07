class Solution {
public:
    string reverseVowels(string s) {
         vector<char>c;
        
        for(int i =0 ; i< s.length(); i++){
            if(s[i] == 'a' || s[i] == 'e' ||s[i] == 'i' ||s[i] == 'o' ||s[i] == 'u' ||s[i] == 'A' ||s[i] == 'E' ||s[i] == 'I' ||s[i] == 'O' ||s[i] == 'U'){
                c.push_back(s[i]);
            }
            
        }
        int j = 0;
        for(int i =0 ; i< s.length(); i++){
            if(s[i] == 'a' || s[i] == 'e' ||s[i] == 'i' ||s[i] == 'o' ||s[i] == 'u' ||s[i] == 'A' ||s[i] == 'E' ||s[i] == 'I' ||s[i] == 'O' ||s[i] == 'U'){
                s[i] = c[c.size() - 1-j++];
            }
            
        }
        
        return s;
    }
};