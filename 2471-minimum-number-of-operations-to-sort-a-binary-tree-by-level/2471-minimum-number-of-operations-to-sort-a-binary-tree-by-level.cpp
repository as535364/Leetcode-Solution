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
    int levelSwap(vector<int> &source) {
        int n = source.size();
        vector<int> target = source;
        sort(begin(target), end(target));
        
        unordered_map<int, int> valIdx;
        for (int i = 0; i < n; ++i) valIdx[source[i]] = i;

        int swapCount = 0;
        for (int i = 0; i < n; ++i) {
            if (source[i] != target[i]) {
                // source[i] at valIdx[source[i]]
                // target[i] at valIdx[target[i]]
                int curPos = valIdx[target[i]];
                valIdx[source[i]] = curPos;
                swap(source[curPos], source[i]);
                swapCount++;
            }
        }
        return swapCount;
    }
public:
    int minimumOperations(TreeNode* root) {
        int ans = 0;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int n = q.size();
            vector<int> level(n);
            for (int i = 0; i < n; ++i) {
                TreeNode *now = q.front();
                q.pop();
                level[i] = now -> val;
                if (now -> left) q.push(now -> left);
                if (now -> right) q.push(now -> right);
            }
            ans += levelSwap(level);
        }
        return ans;
    }
};