class Node{
    public:
    vector<Node*>children{26,NULL};
    bool is_end = false;
};
class WordDictionary {
private:
    bool search(string&word, int pos,Node*root){
        if(pos==word.length())
            return root->is_end;
        if(word[pos]!='.'){
            if(root->children[word[pos]-'a']==NULL)return false;
            else return search(word,pos+1,root->children[word[pos]-'a']);
        }
        else{
            for(auto&child_ptr:root->children){
                if(child_ptr!=NULL&&search(word,pos+1,child_ptr))
                    return true;
            }
            return  false;
        }
        return false;
    }
public:
    Node*root = new Node();
    /** Initialize your data structure here. */
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        Node*temp = root;
        for(auto&ch:word){
            if(temp->children[ch-'a']==NULL)
                temp->children[ch-'a']= new Node();
            temp = temp->children[ch-'a'];
        }
        temp->is_end = true;
    }
    
    bool search(string word) {
        Node*temp = root;
        return search(word,0,temp);
    }
};
/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */