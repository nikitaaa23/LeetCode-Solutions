/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    TreeNode* dfs(TreeNode* root){
        if(!root)
            return NULL;
        TreeNode* lefttail = dfs(root->left);
        TreeNode* righttail = dfs(root->right);
        
        if(root->left!=NULL){
            lefttail->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }
         TreeNode* last;
        if(righttail){
           last = righttail;
        }
        else if(lefttail){
            last = lefttail;
        }
        else{
            last = root;
        }
        return last;
    }
    void flatten(TreeNode* root) {
        dfs(root);
    }
};