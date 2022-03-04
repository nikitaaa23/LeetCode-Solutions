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
    vector<int>ans;
    
//     void solve(TreeNode* root){
//         if(root==NULL)
//             return;
        
//         solve(root->left);
//         ans.push_back(root->val);
//         solve(root->right);
//     }
    vector<int> inorderTraversal(TreeNode* root) {
//         solve(root);
        
//         return ans;
        
        stack<TreeNode*>s;
        TreeNode* curr = root;
        while(curr!=NULL || !s.empty()){
            while(curr!=NULL){
                s.push(curr);
                curr=curr->left;
            }
            curr = s.top();
            s.pop();
            ans.push_back(curr->val);
            curr = curr->right;
        }
        return ans;
    }
};