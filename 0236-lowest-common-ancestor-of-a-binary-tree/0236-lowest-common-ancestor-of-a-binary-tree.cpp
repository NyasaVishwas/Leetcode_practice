/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    map<TreeNode*, TreeNode*> parent;
    void dfs(TreeNode* root, TreeNode* par){
      if (!root) return;
      parent[root] = par;
      dfs(root->left, root);
      dfs(root->right, root);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> ancestorP;
        vector<TreeNode*> ancestorQ;
        dfs(root, NULL);
        TreeNode* currP = p;
        while (currP != NULL){
            ancestorP.push_back(currP);
            currP = parent[currP];
        }
        TreeNode* currQ = q;
        while (currQ != NULL){
            ancestorQ.push_back(currQ);
            currQ = parent[currQ];
        }
        int i = 0;
        TreeNode* ans = NULL;
        int sizeP = ancestorP.size();
        int sizeQ = ancestorQ.size();
        while (i < sizeP && i < sizeQ && ancestorP[sizeP - 1 - i] == ancestorQ[sizeQ - 1 - i]){
            ans = ancestorP[sizeP - 1 - i];
            i++;
        }
        return ans;
    }
};