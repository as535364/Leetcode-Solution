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
    int val, left, right;
    int dfs(TreeNode *node) {
        if (node == nullptr) return 0;

        if (node -> val == val) {
            left = dfs(node -> left);
            right = dfs(node -> right);
            return 1 + left + right;
        }
        else return 1 + dfs(node -> left) + dfs(node -> right);
    }
public:
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        val = x;
        dfs(root);
        // left, right, n - left - right - 1
        return left > n / 2 || right > n / 2 || n - left - right - 1 > n / 2;
    }
};