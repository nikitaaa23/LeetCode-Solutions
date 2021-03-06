/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    
    Node* findNext(Node* root){
        if(!root)
            return NULL;
        if(root->left)
            return root->left;
        if(root->right)
            return root->right;
       return findNext(root->next);
    }
    void populate(Node* root){
        if(!root)
            return;
        if(root->left)
            root->left->next = root->right ? root->right:findNext(root->next);
        if(root->right)
            root->right->next = findNext(root->next);
        
        populate(root->right);
        populate(root->left);
    }
    Node* connect(Node* root) {
        if(!root)
            return NULL;
        populate(root);
        
        return root;
    }
};