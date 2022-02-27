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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL) 
        return 0;
        queue<pair<TreeNode*,unsigned long long int>>q;
        q.push({root,1});
        int res=0;
        while(!q.empty()){
            int n=q.size();
            int d=q.back().second-q.front().second+1;
            res=max(res,d);
            for(int i=0;i<n;i++)
            {
                TreeNode *curr = q.front().first;
                auto ds = q.front().second;
                
                if(curr->left!=NULL) 
                q.push({curr->left,ds*2});
                if(curr->right!=NULL) 
                q.push({curr->right,ds*2+1});
                q.pop();
            }
        }
        return res;
    }
};