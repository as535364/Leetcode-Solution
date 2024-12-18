class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> ans(n, -1);

        for (int i = 0; i < 2 * n; ++i) {
            while (!st.empty() && nums[st.top()] < nums[i % n]) {
                int idx = st.top();
                st.pop();
                ans[idx] = nums[i % n];
            }
            st.push(i % n);
        }
        return ans;
    }
};