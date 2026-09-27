/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    int helper(TreeNode* root, TreeNode* p, TreeNode* q,TreeNode* &ans){
        if(!root) return 0;

        int left = helper(root->left,p,q,ans);
        int right = helper(root->right,p,q,ans);
        
        if((left == 1 && right == 1) || ((left == 1 || right == 1) && (root->val == p->val || root->val == q->val))) ans = root;
        if((root->val == p->val) || (root->val == q->val)) return 1;

        

        return max(left,right);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = NULL;

        helper(root,p,q,ans);

        return ans;
    }
};