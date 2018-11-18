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
    
    bool makeAncestor(vector<TreeNode*> &ret, TreeNode *root, TreeNode *p){
        if(root == NULL) return false;
        
        if(root->val == p->val){
            ret.emplace_back(root);
            return true;
        }
        bool l = makeAncestor(ret, root->left, p);
        if(l){
            ret.emplace_back(root);
            return true;
        }
        bool r = makeAncestor(ret, root->right, p);
        if(r){
            ret.emplace_back(root);
            return true;
        }
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        
        vector<TreeNode*> pans;
        makeAncestor(pans, root, p);
        unordered_set<TreeNode *> aux(pans.begin(), pans.end());
        vector<TreeNode*> qans;
        makeAncestor(qans, root, q);
        for(auto i : qans){
            if(aux.count(i)==1)return i;

        }
        
        
        
        return NULL;
    }
};
