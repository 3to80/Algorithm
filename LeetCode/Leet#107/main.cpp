tion for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// traversal 하며 각 레벨을 구하고, vector< vector<int> > aux 에 넣고, 마지막에 출력
// 
class Solution {
public:
    vector<vector<int>> ret;
    int maxLevel;
    int getMaxLevel(TreeNode *root){
        
        if(root == NULL) return 0;
        int leftLevel = getMaxLevel(root->left);
        int rightLevel = getMaxLevel(root->right);
        return max(leftLevel, rightLevel) + 1;
    
    }
    
    void fill(TreeNode *root, int tracing){
        // get Current Level : 
        // file in ret
        int reverse_Level = maxLevel - tracing-1;
        ret[reverse_Level].emplace_back(root->val);
        if(root->left != NULL) fill(root->left, tracing+1);
        if(root->right != NULL) fill(root->right, tracing+1);
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        maxLevel = getMaxLevel(root);
        if(maxLevel == 0) return ret;
        ret.clear();
        for(int i = 0 ; i < maxLevel; ++i)
            ret.emplace_back(vector<int>());

        fill(root, 0);
        return ret;
    }
    

    
};
