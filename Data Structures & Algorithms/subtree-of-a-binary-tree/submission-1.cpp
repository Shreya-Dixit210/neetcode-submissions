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

    bool isIdentical(TreeNode* p , TreeNode* q){
        if(p == NULL || q == NULL){
            return p == q; 
        }
        bool isleft = isIdentical(p->left , q->left);
        bool isright = isIdentical(p->right , q->right);
        return isleft && isright && p->val == q->val;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL || subRoot == NULL){
            return root == subRoot;
        }
        if(root->val == subRoot->val && isIdentical(root , subRoot) ){
            return true;
        }
        bool leftSub = isSubtree(root->left , subRoot);
        bool rightSub = isSubtree(root->right , subRoot);
        return leftSub || rightSub;
    }
};
