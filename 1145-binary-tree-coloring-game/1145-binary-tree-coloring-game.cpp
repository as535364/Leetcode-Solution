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
    int val = 0, left = 0, right = 0;
    int dfs(TreeNode *node) {
        if (node == nullptr) return 0;
        if (node -> val == val) {
            left = dfs(node -> left), right = dfs(node -> right);
            return 1 + left + right;
        }
        return 1 + dfs(node -> left) + dfs(node -> right);
    }
public:
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        // left, right, n - left - right - 1
        // left > n / 2
        val = x;
        dfs(root);
        return max({left, right, n - left - right - 1}) > n / 2;
    }
};