class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        stack<int> st;
        for (int num : arr) {
            int maxInSt = -1;
            while (!st.empty() && st.top() > num) {
                maxInSt = max(maxInSt, num);
                st.pop();
            }
            if (maxInSt != -1) {
                st.push(maxInSt);
            }
            else {
                st.push(num);
            }
        }
        return st.size();
    }
};