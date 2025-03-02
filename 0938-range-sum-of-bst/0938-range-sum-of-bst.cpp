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
    int sum = 0, low_, high_;
    void dfs(TreeNode *node) {
        if (node == nullptr) return;
        if (low_ <= node -> val && node -> val <= high_) sum += node -> val;
        dfs(node -> left);
        dfs(node -> right);
    }
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        low_ = low;
        high_ = high;
        dfs(root);
        return sum;
    }
};