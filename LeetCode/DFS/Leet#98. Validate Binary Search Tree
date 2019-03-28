/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */



int minV, maxV;


class Solution {
public:


    bool isValidBST(TreeNode* root) {
        if(not root) return true;
        
        int tmin, tmax; // root값을 root로 하는 tree의 최소, 최대값        
        if(not root->left) tmin = root->val;
        else{
            // 현재 minV, maxV는 root->left를 root로 하는 트리의 최소, 최대 값.
            bool lval = isValidBST(root->left);
            if(not lval or (maxV >= root->val)) return false;
            tmin = minV;
        }
        
        if(not root->right) tmax = root->val;
        else{
            bool rval = isValidBST(root->right);
            if(not rval or (minV <= root->val)) return false;
            tmax = maxV;
        }
        
        minV = tmin;
        maxV = tmax;
        return true;
        
        
    }
};
