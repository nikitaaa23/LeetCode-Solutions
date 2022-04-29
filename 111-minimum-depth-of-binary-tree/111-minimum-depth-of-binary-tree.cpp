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
    int minDepth(TreeNode* root) {
        if(root==NULL)
            return 0;
        
        queue<TreeNode*>q;
        q.push(root);
        int dp = 1;
        while(!q.empty()){
            int n = q.size();
            int count = 1;
            while(n--){
                auto t = q.front();
                q.pop();
                if(!t->left && !t->right)
                    return dp;
                if(t->left)
                    q.push(t->left);
                
                if(t->right)
                    q.push(t->right);
               
            }
            dp++;
        }
        return dp;
    }
};