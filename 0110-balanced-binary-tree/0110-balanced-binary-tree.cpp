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
    bool isBalanced(TreeNode* root) {
        auto [bRoot, hRoot] = helper(root);
        return bRoot;
    }
    pair<bool, int> helper(TreeNode* root){
        if (!root) return {true, 0}; //null pointer is balanced
        auto [bLeft, hLeft] = helper(root->left);
        auto [bRight, hRight] = helper(root->right);
        if (!bLeft || !bRight) return {false, -1};//height doesn't matter
        //both subtrees are balanced
        if (abs(hLeft - hRight) > 1) return {false, -1}; //imbalanced
        return {true, max(hLeft, hRight) + 1};
    }
};