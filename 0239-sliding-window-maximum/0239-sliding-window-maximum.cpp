class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;

        for (int i = 0; i < nums.size(); ++i) {
            // 入
            while (!dq.empty() && nums[dq.back()] <= nums[i]) dq.pop_back();
            dq.push_back(i);

            // 出
            if (i - dq.front() + 1 > k) dq.pop_front();

            // 更新答案
            if (i >= k - 1) ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};