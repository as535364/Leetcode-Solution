class Solution {
public:
    vector<int> maximumLengthOfRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n), right(n);
        stack<int> idxStack;

        // Calculate left boundaries
        for (int currIdx = 0; currIdx < n; ++currIdx) {
            while (!idxStack.empty() && nums[idxStack.top()] < nums[currIdx]) {
                idxStack.pop();
            }
            left[currIdx] = idxStack.empty() ? -1 : idxStack.top();
            idxStack.push(currIdx);
        }

        // Clear the stack for reuse
        while (!idxStack.empty()) idxStack.pop();

        // Calculate right boundaries
        for (int currIdx = n - 1; currIdx >= 0; --currIdx) {
            while (!idxStack.empty() && nums[idxStack.top()] < nums[currIdx]) {
                idxStack.pop();
            }
            right[currIdx] = idxStack.empty() ? n : idxStack.top();
            idxStack.push(currIdx);
        }

        // Calculate the maximal range for each element
        vector<int> maxRanges(n);
        for (int currIdx = 0; currIdx < n; ++currIdx) {
            maxRanges[currIdx] = right[currIdx] - left[currIdx] - 1;
        }

        return maxRanges;
    }
};