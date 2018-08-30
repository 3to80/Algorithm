/*Solution for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */



class Solution {
public:
 

    int find(vector<int>& inorder , int start, int end, int targetVal){
        
        for(int i = start ; i < end ; ++i){
            if(inorder[i] == targetVal) return i;
        }
        return -1;
        
    }
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int start, int end, int &rootIdx){
        if(end - start == 0) return NULL;

        TreeNode * root = new TreeNode(preorder[rootIdx]);
        rootIdx += 1;

            
        
        int splitIdx = find(inorder, start, end, root->val);

        root->left = solve(preorder, inorder, start, splitIdx, rootIdx);                        
        root->right = solve(preorder, inorder, splitIdx+1, end, rootIdx);                        
        
        return root;
        
    }
    
    
    
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int rootIdx = 0;
        return solve(preorder, inorder, 0, preorder.size(), rootIdx);
    }
    

    
    
};
