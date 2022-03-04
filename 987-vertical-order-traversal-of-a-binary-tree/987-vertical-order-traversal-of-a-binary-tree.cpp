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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL) return ans;
        map<int, vector<int>>mp2;
        queue<pair<TreeNode*, int>>q;
        q.push({root, 0});
        
       while(!q.empty()){
           int n = q.size();
           map<int, vector<int>>mp;
           for(int i= 0; i<n; i++){
                
           auto t =q.front().first;
           int h =q.front().second;
           q.pop();
           
           mp[h].push_back(t->val);
           if(t->left){
               q.push({t->left, h-1});
           }
           if(t->right){
               q.push({t->right, h+1});
           }
           }
           
           for(auto x: mp){
           sort(x.second.begin(), x.second.end());
               for(auto p : x.second)
                   mp2[x.first].push_back(p);
            }
       }
        for(auto x : mp2){
            ans.push_back(x.second);
        }
       
       
       return ans;
    }
};