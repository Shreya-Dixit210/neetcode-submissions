/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL){
            return NULL;
        }
        if(p->val == root->val || q->val == root->val){
            return root;
        }
        TreeNode* leftlca = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightlca = lowestCommonAncestor(root->right, p, q);
        if(leftlca && rightlca != NULL){
            return root;
        }else if(leftlca == NULL){
            return rightlca;
        }else{
            return leftlca;
        }
    }
};
