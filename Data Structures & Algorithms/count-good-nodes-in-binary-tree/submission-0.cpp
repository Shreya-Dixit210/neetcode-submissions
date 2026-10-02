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
    int count=0;
    void good(TreeNode* root , int maxVal){
        if(root == NULL)
            return;
        
        if(maxVal <= root->val){
            count ++;
            maxVal = root->val;
        }
        good(root->left , maxVal);
        good(root->right , maxVal);
        
    }
        
    int goodNodes(TreeNode* root) {
        int maxVal = root->val;
        good(root,maxVal);
        return count;
    }
};
