/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


TreeNode *before = new TreeNode(-987654321);
vector<TreeNode *> vec;

class Solution {
public:
    
    // Time : O(n) , Space : O(1)
    void recoverRecur(TreeNode* root) {
        // inorder를 한다. 이전 값을 항상 들고 있는다.
        // 이전 값보다 현재 값이 작은 경우, 이 값은 swap 대상이 되는 node이다. 
        if(root == NULL) return;
        recoverRecur(root->left);        
        if(before->val > root->val){
            vec.emplace_back(before);
            vec.emplace_back(root);
        }
        before = root;
        recoverRecur(root->right);
    }    
    
    void recoverTree(TreeNode *root){
        before = new TreeNode(-987654321);
        vec.clear();

        recoverRecur(root);
        int tmp = vec[vec.size()-1]->val;
        vec[vec.size()-1]->val = vec[0]->val;
        vec[0]->val = tmp;    
    }
    
//    Time : O(n) , Space : O(n)
//     void makeInorder(TreeNode *iter, vector<TreeNode* > &inorder){
//         if(iter == NULL) return;
//         makeInorder(iter->left, inorder);
//         inorder.emplace_back(iter);
//         makeInorder(iter->right, inorder);
//         return;         
//     }
//     // 양 옆에 PADDING 값을 하나씩 넣음
//     vector<TreeNode* > makeInorder(TreeNode *root){
//         vector<TreeNode *> ret;
//         TreeNode *left_pad = new TreeNode(-1);
//         TreeNode *right_pad = new TreeNode(987654321);
//         ret.emplace_back(left_pad);
//         makeInorder(root, ret);        
//         ret.emplace_back(right_pad);
//         return ret;
//     }
//     void recoverTree(TreeNode* root) {
//        // root를 기점으로 inorder list를 만든다.
//         vector<TreeNode *> inorder = makeInorder(root);
//         //inorder list에서 양 옆보다 그 값이 더 큰 것과 그 값이 더 작은 것을 찾는
//         TreeNode *a; // 양쪽보다 더 큰 node
//         TreeNode *b; // 양쪽보다 더 작은 node 
//         for(int idx = 1; idx < inorder.size() - 1 ; ++idx){
//             if(inorder[idx-1]->val < inorder[idx]->val 
//                and inorder[idx]->val > inorder[idx+1]->val){
//                 a = inorder[idx];
//                 break;
//             }
//         }
//         for(int idx = inorder.size()-1; idx > 0 ; --idx){
//             if(inorder[idx-1]->val > inorder[idx]->val 
//                and inorder[idx]->val < inorder[idx+1]->val){
//                 b = inorder[idx];
//                 break;
//             }
//         }
//         // swap
//         int tmp = a->val;
//         a->val = b->val;
//         b->val = tmp;

//     }
    
};
