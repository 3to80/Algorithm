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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int diff1 = root->val - p->val;
        int diff2 = root->val - q->val;
        if(diff1 * diff2 <= 0){
            if(diff1 == 0) return p;
            else if(diff2 ==0) return q;
            else return root;
        }
        else{
            if(diff1 > 0) return lowestCommonAncestor(root->left, p, q);
            else return lowestCommonAncestor(root->right, p, q);
        }
        
    }
};
