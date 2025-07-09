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
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode *successor = nullptr;
        while(root != nullptr){
            if(root -> val <= p -> val){
                root = root -> right;
            }
            else {
                successor = root;
                root = root -> left;
            }
        }
        return successor;
    }
    // bool dfs(TreeNode *node, TreeNode *p, TreeNode* &res){
    //     if(node == nullptr)return false;
    //     if(dfs(node -> right, p, res)){
    //         return true;
    //     }
    //     if(node == p)return true;
    //     res = node;
    //     if(dfs(node -> left, p, res)){
    //         return true;
    //     }
    //     else return false;
    // }
};