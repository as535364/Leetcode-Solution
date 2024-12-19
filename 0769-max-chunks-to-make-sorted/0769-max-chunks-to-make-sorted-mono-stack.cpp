class Solution {
private:

public:
    int maxChunksToSorted(vector<int>& arr) {
        stack<int> st;
        for (int num : arr) {
            int maxInSt = INT_MIN;
            while (!st.empty() && st.top() > num) {
                maxInSt = max(maxInSt, st.top());
                st.pop();
            }
            if (maxInSt != INT_MIN) {
                st.push(maxInSt);
            }
            else {
                st.push(num);
            }
        }
        return st.size();
    }
};