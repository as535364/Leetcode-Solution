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
private:
    TreeNode *dfs(TreeNode *node, TreeNode *left, TreeNode *right, int level) {
        if (left == nullptr) return node;
        if (level % 2 == 0) swap(left -> val, right -> val);
        dfs(left, left -> left, right -> right, level + 1);
        dfs(right, left -> right, right -> left, level + 1);
        return node;
    }
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        return dfs(root, root -> left, root -> right, 0);        
    }
};