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
class FindElements {
private:
    unordered_set<int> seen;
public:
    FindElements(TreeNode* root) {
        stack<TreeNode*> st;
        root -> val = 0;
        st.push(root);
        while (!st.empty()) {
            TreeNode *node = st.top(); st.pop();
            seen.insert(node -> val);
            if (node -> left) {
                node -> left -> val = node -> val * 2 + 1;
                st.push(node -> left);
            }
            if (node -> right) {
                node -> right -> val = node -> val * 2 + 2;
                st.push(node -> right);
            }
        }
    }
    
    bool find(int target) {
        return seen.find(target) != seen.end();
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */