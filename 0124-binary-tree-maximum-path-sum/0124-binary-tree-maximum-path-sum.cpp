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
    int maxPathSum(TreeNode* root) {
        int maxPathSum = 0;
        dfs(maxPathSum, root);
        return maxPathSum;
    }
    int dfs(int &maxPathSum, TreeNode *node){
        if(node == nullptr)return 0;
        int leftSubtreeAns = max(0, dfs(maxPathSum, node -> left));
        int rightSubtreeAns = max(0, dfs(maxPathSum, node -> right));
        maxPathSum = max(maxPathSum, node -> val + leftSubtreeAns + rightSubtreeAns);
        return max(leftSubtreeAns, rightSubtreeAns) + node -> val;
    }
};