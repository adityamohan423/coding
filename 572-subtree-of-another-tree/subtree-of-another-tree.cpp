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
    bool checkSub(TreeNode* root, TreeNode* subRoot){
        if(!root && !subRoot) return true;  
        if(!root || !subRoot) return false;

        if(root->val != subRoot->val) return false;

        bool left = checkSub(root->left,subRoot->left);
        bool right = checkSub(root->right,subRoot->right);

        return left && right;

    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root) return 0;

        bool ans = checkSub(root,subRoot);
        if(ans == true) return 1;

        bool left = isSubtree(root->left,subRoot);
        bool right = isSubtree(root->right,subRoot);

        return left || right;
    }
};