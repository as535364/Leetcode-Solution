class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        sort(queries.begin(), queries.end());
        int used = 0;
        priority_queue<int> candidate; // max heap -> tend to use the last query
        priority_queue<int, vector<int>, greater<>> chosen; // min heap -> tend to pop when query is not available for specify index

        int j = 0;
        for (int i = 0; i < nums.size(); ++i) {
            while (j < queries.size() && queries[j][0] == i) {
                candidate.push(queries[j++][1]);
            }

            nums[i] -= chosen.size();

            while (nums[i] > 0 && !candidate.empty()) {
                nums[i]--;
                used++;
                chosen.push(candidate.top());
                candidate.pop();
            }

            if (nums[i] > 0) return -1;

            while (!chosen.empty() && chosen.top() == i) {
                chosen.pop();
            }
        }
        return queries.size() - used;        
    }
};