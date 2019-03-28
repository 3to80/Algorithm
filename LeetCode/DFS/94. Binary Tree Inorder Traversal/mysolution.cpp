/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


struct Data{
    
    TreeNode *node;
    bool status;
    Data(TreeNode* _n, bool _s) : node(_n), status(_s) {};
    
};

class Solution {
public:
    void inOrderRecursive(TreeNode *root, vector<int> &ret){
        if(not root)return;
        inOrderRecursive(root->left, ret);
        ret.emplace_back(root->val);
        inOrderRecursive(root->right, ret);
    }
    
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        // inOrderRecursive(root, ret);
        if(not root) return ret;
        //init
        stack<Data> s;
        s.push(Data(root, false));
        while(not s.empty()){
            auto t = s.top();
            s.pop();
            if(not t.status){
                if(t.node->right)s.push(Data(t.node->right, false));
                s.push(Data(t.node, true));
                if(t.node->left)s.push(Data(t.node->left, false));
            }else ret.emplace_back(t.node->val);
        }
        return ret;
        
        
        

        
    }
};
