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
    int ans = 0;
    int dfs(TreeNode *node) {
        if (!node) return 0;
        int left = dfs(node -> left), right = dfs(node -> right);
        ans += abs(left) + abs(right);
        return left + right + node -> val - 1;
    }
public:
    int distributeCoins(TreeNode* root) {
        dfs(root);
        return ans;
    }
};