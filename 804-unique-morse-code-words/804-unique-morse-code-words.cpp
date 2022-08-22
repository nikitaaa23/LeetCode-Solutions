class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
         string morseCode[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        set<string>st;
        
        for(int i = 0 ;i<words.size(); i++){
            string s;
            for(int j = 0; j<words[i].size(); j++){
                s+=morseCode[words[i][j]-'a'];
            }
            st.insert(s);
        }
        return st.size();
    }
};