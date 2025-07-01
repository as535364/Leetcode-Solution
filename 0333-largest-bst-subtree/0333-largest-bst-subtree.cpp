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
    int res = 0;
    tuple<bool, int, int, int> dfs(TreeNode *root) {
        if (root == nullptr) return {true, 0, 0, 0};
        auto [isleftBST, leftNodes, leftMin, leftMax] = dfs(root -> left);
        auto [isrightBST, rightNodes, rightMin, rightMax] = dfs(root -> right);
        
        int nodes = leftNodes + rightNodes + 1;
        int minVal = root -> val, maxVal = root -> val;
        bool isBST = isleftBST && isrightBST;

        if (leftNodes != 0) {
            isBST = isBST && root -> val > leftMax;
            minVal = min(leftMin, minVal);
            maxVal = max(leftMax, maxVal);
        }
        if (rightNodes != 0) {
            isBST = isBST && root -> val < rightMin;
            minVal = min(rightMin, minVal);
            maxVal = max(rightMax, maxVal);
        }

        if (leftNodes == 0 && rightNodes == 0) {
            minVal = root -> val;
            maxVal = root -> val;
        }
        if (isBST) res = max(res, nodes);
        return {isBST, nodes, minVal, maxVal};
    }
public:
    int largestBSTSubtree(TreeNode* root) {
        dfs(root);
        return res;
    }
};