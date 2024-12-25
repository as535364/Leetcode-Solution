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
    vector<int> largestValues(TreeNode* root) {
        if(root == nullptr)return vector<int>{};
        
        vector<int> ans;
        queue<TreeNode *> q;
        q.push(root);

        while(!q.empty()){
            int nowLevelLen = q.size(), levelMax = INT_MIN;
            for(int i = 0; i < nowLevelLen; ++i){
                TreeNode *now = q.front();
                q.pop();
                levelMax = max(levelMax, now -> val);
                if(now -> left)q.push(now -> left);
                if(now -> right)q.push(now -> right);
            }
            ans.push_back(levelMax);
        }
        return ans;
    }
};