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
    int search(TreeNode* root , vector<int>& inorder , int left , int right){
        for(int i= left; i<=right; i++){
            if(root->val == inorder[i]){
                return i;
            }
        }
        return -1;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder , int &preidx , int left , int right){
        if(left > right){
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[preidx]);
        preidx++;
        int idx = search(root,inorder, left , right);
        root->left = buildTree(preorder , inorder , preidx , left , idx-1);
        root->right = buildTree(preorder , inorder , preidx ,idx+1 , right);
        return root;

    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int left = 0;
        int right = inorder.size()-1;
        int preidx = 0;
        return buildTree(preorder , inorder , preidx , left , right );
    }
};
