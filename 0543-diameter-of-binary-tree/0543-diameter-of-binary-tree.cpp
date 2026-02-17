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
    int diameter = INT_MIN;
    int diameterOfBinaryTree(TreeNode* root){
        height(root);
        return diameter;
    }
    int height(TreeNode* root){
        if (!root) return 0;
        int left = height(root->left);
        int right = height(root->right);
        diameter = max(diameter, left + right);
        return max(left,right)+1;
    }
};