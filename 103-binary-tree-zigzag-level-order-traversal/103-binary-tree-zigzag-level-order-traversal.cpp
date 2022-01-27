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
    vector<vector<int>>ans;    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL) return ans;
        
        queue<TreeNode*>q;
        q.push(root);
        int level = 1;
        
        while(!q.empty()){
            int n = q.size();
            vector<int>v;
            for(int i = 0; i<n; i++){
                auto t = q.front();
                q.pop();
                v.push_back(t->val);
                
                if(t->left){
                    q.push(t->left);
                }
                if(t->right){
                    q.push(t->right);
                }
            }
            
            if(level%2!=0){
                ans.push_back(v);
            }
            else{
                reverse(v.begin(), v.end());
                ans.push_back(v);
            }
            level++;
        }
        return ans;
    }
};