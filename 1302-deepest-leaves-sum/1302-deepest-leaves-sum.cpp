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
    int solve(TreeNode* root){
        if(root==NULL)
            return 0;
       
        return 1 + max(solve(root->left), solve(root->right));
    }
    int deepestLeavesSum(TreeNode* root) {
        int height = solve(root);
        
        if(height == 0)
            return 0;
        if(height == 1)
            return root->val;
        
        queue<TreeNode*>q;
        int sum;
        q.push(root);
        int h = 1;
        while(!q.empty()){
            sum = 0;
            int n = q.size();
            while(n--){
                auto t = q.front();
                q.pop();
        
                    sum+=t->val;
                if(t->left)
                    q.push(t->left);
                if(t->right)
                    q.push(t->right);
            }
            
        }
        return sum;
    }
};