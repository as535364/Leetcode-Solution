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
    pair<int, int> longestConsecutiveSubroot(TreeNode *root) {
        if (root == nullptr) return {0, 0};
        auto left_res = longestConsecutiveSubroot(root -> left);
        auto right_res = longestConsecutiveSubroot(root -> right);
        pair<int, int> res;
        res.first = 1;
        res.second = max({left_res.first, left_res.second, right_res.first, right_res.second});

        if (root -> left != nullptr && root -> left -> val - root -> val == 1) {
            res.first = max(res.first, left_res.first + 1);
        }
        if (root -> right != nullptr && root -> right -> val - root -> val == 1) {
            res.first = max(res.first, right_res.first + 1);
        }
        return res;
    }
public:
    int longestConsecutive(TreeNode* root) {
        auto res = longestConsecutiveSubroot(root);
        return max(res.first, res.second);
    }
};