class Solution {
public:
    long long findScore(vector<int>& nums) {
        nums.push_back(1e6);

        long long score = 0;
        stack<int> st;

        for (int num : nums) {
            if (st.empty() || st.top() > num) st.push(num);
            else {
                while (!st.empty()) {
                    score += st.top();
                    st.pop();
                    if (!st.empty()) st.pop();
                }
            }
        }
        return score;
    }
};