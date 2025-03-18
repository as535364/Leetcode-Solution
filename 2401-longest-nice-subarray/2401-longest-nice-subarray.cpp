class Solution {
private:
    // return true means nice
    bool add(vector<int> &cnt, int x) {
        bool nice = true;
        for (int i = 0; i < 32; ++i) {
            if (x & 1) cnt[i]++;
            if (cnt[i] > 1) nice = false;
            x >>= 1;
        }
        return nice;
    }
    bool remove(vector<int> &cnt, int x) {
        bool nice = true;
        for (int i = 0; i < 32; ++i) {
            if (x & 1) cnt[i]--;
            nice = nice && (cnt[i] <= 1);
            x >>= 1;
        }
        return nice;
    }
public:
    int longestNiceSubarray(vector<int>& nums) {
        vector<int> cnt(32);
        int res = 0, left = 0;

        for (int right = 0; right < nums.size(); ++right) {
            bool nice = add(cnt, nums[right]);
            while (!nice) {
                nice = remove(cnt, nums[left]);
                left++;
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};