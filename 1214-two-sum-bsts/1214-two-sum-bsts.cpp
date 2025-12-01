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
    bool isExist(TreeNode *root, int target) {
        if (root == nullptr) return false;
        if (root -> val == target) return true;
        if (root -> val < target) return isExist(root -> right, target);
        if (root -> val > target) return isExist(root -> left, target);
        return false;
    }

    bool ans = false;
    void dfs(TreeNode *root1, TreeNode *root2, int target) {
        if (root1 == nullptr) return;
        int complement = target - root1 -> val;
        ans = ans || isExist(root2, complement);
        dfs(root1 -> left, root2, target);
        dfs(root1 -> right, root2, target);
    }
public:
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        dfs(root1, root2, target);
        return ans;
    }
};