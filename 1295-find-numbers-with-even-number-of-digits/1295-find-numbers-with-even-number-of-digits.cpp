class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int cnt = 0;
        for (int num : nums) {
            int digit = log10(num) + 1;
            cnt += digit % 2 == 0;
        }
        return cnt;
    }
};