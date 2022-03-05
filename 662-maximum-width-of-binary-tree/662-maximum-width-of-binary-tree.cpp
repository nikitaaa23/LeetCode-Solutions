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
            int n = q.size();
            int d = q.back().second - q.front().second + 1;
           
            for(int i = 0; i<n; i++){
                auto t = q.front();
                auto d = q.front().second;
                q.pop();
            
                if(t.first->left){
                    q.push({t.first->left, 2*d});
                }
                if(t.first->right){
                    q.push({t.first->right, 2*d+1});
                }
               
            }
            res = max(d, res);
        }
        return res;
    }
};