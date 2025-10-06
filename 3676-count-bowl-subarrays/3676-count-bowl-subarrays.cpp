class Solution {
public:
    long long bowlSubarrays(vector<int>& nums) {
        long long ans = 0;
        stack<int> st;
        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            while (!st.empty() && nums[st.top()] <= num) {
                if (i - st.top() > 1) ++ans;
                st.pop();
            }
            if (!st.empty() && i - st.top() > 1) ++ans;
            st.push(i);
        }
        return ans;
    }
};