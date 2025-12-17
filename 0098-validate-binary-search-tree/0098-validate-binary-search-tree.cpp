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
    bool res = true;
    pair<int, int> dfs(TreeNode *node) {
        int min_val = node -> val, max_val = node -> val;

        if (node -> left != nullptr) {
            auto left_res = dfs(node -> left);
            res = res && left_res.second < node -> val;
            min_val = min(min_val, left_res.first);
            max_val = max(max_val, left_res.second);
        }
        if (node -> right != nullptr) {
            auto right_res = dfs(node -> right);
            res = res && right_res.first > node -> val;
            min_val = min(min_val, right_res.first);
            max_val = max(max_val, right_res.second);
        }
        return {min_val, max_val};
    }
public:
    bool isValidBST(TreeNode* root) {
        dfs(root);
        return res;
    }
};