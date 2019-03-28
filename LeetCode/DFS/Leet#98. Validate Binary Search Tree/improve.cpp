/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


typedef long long LL;


class Solution {
public:
    //root->val값을 가지고 비교를 하면 된다. 
    bool recur(TreeNode *root, LL minVal, LL maxVal){
        if(not root) return true;
        if(root->val <= minVal or root->val >= maxVal) return false;
        return recur(root->left, minVal, root->val) and recur(root->right, root->val, maxVal);
    }
    bool isValidBST(TreeNode* root) {
        return recur(root, LLONG_MIN, LLONG_MAX);
    }
};
