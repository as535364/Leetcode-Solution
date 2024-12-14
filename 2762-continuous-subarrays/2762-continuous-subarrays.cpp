class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        map<int, int> count;
        int left = 0;
        long long ans = 0;

        for (int right = 0; right < nums.size(); ++right) {
            ++count[nums[right]];
            while (count.rbegin() -> first - count.begin() -> first > 2) {
                if(--count[nums[left]] == 0) count.erase(nums[left]);
                left++;
            }
            long long len = right - left + 1;
            ans += len;
        }
        return ans;
    }
};