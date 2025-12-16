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
    int res = -1;
    int dfs(TreeNode *node) {
        if (node == nullptr) return 0;
        int left = dfs(node -> left) + 1;
        int right = dfs(node -> right) + 1;

        if (node -> left != nullptr && node -> left -> val - node -> val != 1) {
            left = 1;
        }

        if (node -> right != nullptr && node -> right -> val - node -> val != 1) {
            right = 1;
        }
        int length = max(left, right);
        res = max(res, length);
        return length;
    }
public:
    int longestConsecutive(TreeNode* root) {
        dfs(root);
        return res;
    }
};