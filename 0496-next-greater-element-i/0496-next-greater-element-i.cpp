class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(nums1.size(), -1);
        unordered_map<int, int> nums2NextGreater;
        stack<int> st;

        for (int i = 0; i < nums2.size(); ++i) {
            while (!st.empty() && nums2[st.top()] < nums2[i]) {
                int idx = st.top();
                st.pop();
                nums2NextGreater[nums2[idx]] = nums2[i];
            }
            st.push(i);
        }
        for (int i = 0; i < nums1.size(); ++i) {
            if (!nums2NextGreater.count(nums1[i])) continue;
            ans[i] = nums2NextGreater[nums1[i]];
        }
        return ans;
    }
};