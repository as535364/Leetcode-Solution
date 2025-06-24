class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> maxDeque, minDeque;
        int l = 0, ans = 0;

        for (int r = 0; r < nums.size(); ++r) {
            int x = nums[r];

            // 入
            while (!maxDeque.empty() && maxDeque.back() <= x) {
                maxDeque.pop_back();
            }
            maxDeque.push_back(x);

            while (!minDeque.empty() && minDeque.back() >= x) {
                minDeque.pop_back();
            }
            minDeque.push_back(x);

            // 出
            while (maxDeque.front() - minDeque.front() > limit) {
                if (nums[l] == maxDeque.front()) {
                    maxDeque.pop_front();
                }
                if (nums[l] == minDeque.front()) {
                    minDeque.pop_front();
                }
                ++l;
            }

            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};