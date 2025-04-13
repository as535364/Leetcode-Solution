class Solution {
private:
    const int maxn = 2048;
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;
        
        vector<bool> pairs(maxn), triples(maxn);
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                pairs[nums[i] ^ nums[j]] = true;
            }
        }

        int res = 0;
        for (int i = 0; i < maxn; ++i) {
            if (!pairs[i]) continue;
            for (int j = 0; j < n; ++j) {
                if (!triples[i ^ nums[j]]) {
                    ++res;
                    triples[i ^ nums[j]] = true;
                }
            }
        }
        return res;
    }
};