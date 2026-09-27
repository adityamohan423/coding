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
    void rsv(vector<int> &ans, TreeNode* root,int lev,unordered_map<int,int> &mpp){
        if(!root) return;

        if(mpp.find(lev) == mpp.end()){
            ans.push_back(root->val);
            mpp[lev] = 1;
        }

        rsv(ans,root->right,lev+1,mpp);
        rsv(ans,root->left,lev+1,mpp);

    }
    vector<int> rightSideView(TreeNode* root) {
        unordered_map<int,int> mpp;
        vector<int> ans;

        rsv(ans,root,0,mpp);
        return ans;
    }
};