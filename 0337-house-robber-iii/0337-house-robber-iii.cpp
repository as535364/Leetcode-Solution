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
    unordered_map<TreeNode*, pair<int, int>> dp;
    int dfs(TreeNode *node, bool rob) {
        if (rob && dp[node].first) return dp[node].first;
        if (!rob && dp[node].second) return dp[node].second;
        if (node == nullptr) return 0;
        
        auto &it = dp[node];
        if (rob) {
            it.first = node -> val + dfs(node -> left, 0) + dfs(node -> right, 0);
            return it.first;
        }
        else {
            it.second = max(dfs(node -> left, 0), dfs(node -> left, 1)) + max(dfs(node -> right, 0), dfs(node -> right, 1));
            return it.second;
        }  
    }
public:
    int rob(TreeNode* root) {
        return max(dfs(root, 0), dfs(root, 1));
    }
};