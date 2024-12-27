/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    TreeNode *ans = nullptr;
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        findPQ(root, p, q);
        return ans;
    }
    pair<bool, bool> findPQ(TreeNode *node, TreeNode *p, TreeNode *q) {
        if (node == nullptr) return {false, false};
        auto leftRes = findPQ(node -> left, p, q), rightRes = findPQ(node -> right, p, q);
        if ((leftRes.first && rightRes.second) || (leftRes.second && rightRes.first)) {
            ans = node;
        }
        else if ((node == p && leftRes.second) || (node == p && rightRes.second)) {
            ans = node;
        }
        else if ((node == q && leftRes.first) || (node == q && rightRes.first)) {
            ans = node;
        }

        pair<bool, bool> res;
        res.first = node == p || leftRes.first || rightRes.first;
        res.second = node == q || leftRes.second || rightRes.second;
        return res;
    }
};