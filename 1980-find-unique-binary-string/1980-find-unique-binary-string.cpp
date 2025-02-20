class Solution {
private:
    unordered_set<string> vis;
    string res;

    void dfs(int idx, string& tmp, int n) {
        if (idx == n) {
            if (!vis.count(tmp)) {
                res = tmp;
            }
            return;
        }
        if (!res.empty()) return;
        tmp += "0";
        dfs(idx + 1, tmp, n);
        tmp.pop_back();
        tmp += "1";
        dfs(idx + 1, tmp, n);
        tmp.pop_back();
    }
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string tmp;
        vis = unordered_set<string>(nums.begin(), nums.end());
        dfs(0, tmp, nums[0].length());
        return res;
    }
};