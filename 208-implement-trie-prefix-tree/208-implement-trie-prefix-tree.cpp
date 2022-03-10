class Trie {
public:
    struct TrieNode{
        TrieNode* child[26];
        bool isEnd;
        TrieNode(){
            for(int i = 0; i<26; i++){
                child[i] = NULL;
            }
            isEnd = false;
        }
    };
    
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for(int i = 0; i<word.length(); i++){
            if(curr->child[word[i]-'a']==NULL){
                curr->child[word[i]-'a'] = new TrieNode();
            }
            curr = curr->child[word[i]-'a'];
        }
        curr->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for(int i = 0; i<word.length(); i++){
            if(curr->child[word[i]-'a']==NULL)
                return false;
            curr = curr->child[word[i]-'a'];
        }
        return curr->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for(int i = 0; i<prefix.length(); i++){
            if(curr->child[prefix[i]-'a']==NULL)
                return false;
            curr = curr->child[prefix[i]-'a'];
        }
        return true;
        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */