class Solution {
public:
    int sum = 0;
    void dfs(TreeNode* root, int low, int high){
        if(!root)
            return;
        if(root->val>=low && root->val<=high)
            sum+=root->val;
        dfs(root->left, low, high);
        dfs(root->right, low, high);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        
        dfs(root, low, high);        
        return sum;
    }
};