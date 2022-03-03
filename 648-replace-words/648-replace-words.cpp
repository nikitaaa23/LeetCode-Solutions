class TrieNode {
    public:
    TrieNode* child[26];
    bool isEnd;
    TrieNode(){
        this->isEnd = false;
        for(int i = 0; i<26; i++){
            this->child[i] = NULL;
        }
    }
};

class Solution {
    TrieNode* root;
public:
    
    string check(string word){
        TrieNode* temp =root;
        string s="";
        
        for(auto i : word){
            if(!temp->child[i - 'a'])
                break;
            s+=i;
            temp = temp->child[i-'a'];
            if(temp->isEnd)
                return s;
        }
        return word;
    }
    
    void insert(string word){
        TrieNode* temp = root;
        
        for(auto l : word){
            if(!temp->child[l-'a'])
                temp->child[l-'a'] = new TrieNode();
            temp = temp->child[l-'a'];
        }
        temp->isEnd = true;
    }
    
    string replaceWords(vector<string>& dictionary, string sentence) {
        root = new TrieNode();
        
        for(auto x : dictionary){
            insert(x);
        }
        
        stringstream ss(sentence);
        string word="", ans="";
        
        for(; ss>>word; ){
            ans+=check(word);
            ans+=' ';
        }
        ans.pop_back();
        
        return ans; 
        
    }
};