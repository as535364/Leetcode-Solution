class Solution {
private:
    bool isOK(int maximumCandy, vector<int>& candies, long long k) {
        long long cnt = 0;
        for (int c : candies) {
            cnt += c / maximumCandy;
        }
        return cnt >= k;
    }
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int left = 1, right = *max_element(candies.begin(), candies.end());
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isOK(mid, candies, k)) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return right;
    }
};