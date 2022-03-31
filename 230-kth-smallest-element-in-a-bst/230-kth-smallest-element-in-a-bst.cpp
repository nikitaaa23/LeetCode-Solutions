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
    int ans;
    int kth(TreeNode* root, int &k){
        if(root==NULL)
            return 0;
      
            kth(root->left, k);
        k--;
        if(k==0){
            ans = root->val;
        }
            kth(root->right, k);
        
        return ans;
    }
    
    int kthSmallest(TreeNode* root, int k) {
        return kth(root, k);
    }
};