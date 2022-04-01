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
    
   
    void ans(TreeNode* root, int &mx){
        if(root==NULL)
            return;
        
        ans(root->right, mx);
        mx += root->val;
        root->val = mx;
        ans(root->left, mx);
    }
    TreeNode* bstToGst(TreeNode* root) {
       TreeNode* tmp = root; int mx = 0;
        ans(tmp, mx);
        return tmp;
    }
};