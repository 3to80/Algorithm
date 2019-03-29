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
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        if(not root) return ret;
        stack<TreeNode*> s;
        while(not s.empty() or root){
            while(root){
                s.push(root);
                root = root->left;
            }        
            auto target = s.top();
            s.pop();
            ret.emplace_back(target->val);
            root = target->right;
        }
        return ret;
    }

};
