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
    vector<TreeNode*> rootsAfterDelete;
    
    TreeNode* dfs(TreeNode* node, const unordered_set<int>& toDelete) {
        if (!node) return nullptr;
        node -> left = dfs(node -> left, toDelete);
        node -> right = dfs(node -> right, toDelete);

        if (toDelete.count(node -> val)) {
            if (node -> left) rootsAfterDelete.push_back(node -> left);
            if (node -> right) rootsAfterDelete.push_back(node -> right);
            delete(node);
            return nullptr;
        }
        return node;
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        if (!root) return {};
        
        unordered_set<int> toDelete(to_delete.begin(), to_delete.end());
        
        if (!toDelete.count(root -> val)) rootsAfterDelete.push_back(root);
        dfs(root, toDelete);
        return rootsAfterDelete;
    }
};