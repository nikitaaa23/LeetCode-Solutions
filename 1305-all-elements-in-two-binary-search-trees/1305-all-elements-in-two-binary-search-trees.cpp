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
    void dfs(TreeNode* root1){
        if(!root1)
            return;
        ans.push_back(root1->val);
        dfs(root1->left);
        dfs(root1->right);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
       dfs(root1);
        dfs(root2);
        sort(ans.begin(), ans.end());
        return ans;
    }
};