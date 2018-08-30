tion for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void makeLevelList(deque<vector<int>> &ret, TreeNode *root, int level){
        if(root == NULL) return;
        if(level >= ret.size()) ret.push_front(vector<int>());
        makeLevelList(ret, root->left, level+1);
        makeLevelList(ret, root->right, level+1);
        
        ret[ret.size() - level -1].emplace_back(root->val); 
        
    }
    
    
    
    
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ret;

        deque<vector<int>> dq;
        makeLevelList(dq, root, 0);
        
        for(auto i : dq)
            ret.emplace_back(i);
            
        return ret;
    }
    

    
};
