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
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) return {};

        queue<TreeNode*> q;
        q.push(root);

        vector<vector<int>> res;

        while (!q.empty()) {
            int level_size = q.size();
            vector<int> level;

            for (int i = 0 ; i < level_size; ++i) {
                TreeNode *curr = q.front();
                q.pop();
                level.push_back(curr -> val);
                if (curr -> left != nullptr) q.push(curr -> left);
                if (curr -> right != nullptr) q.push(curr -> right);
            }
            res.push_back(level);
        }
        return res;
    }
};