class Solution {
private:
    bool isOK(const vector<int> &ribbons, int k, int x) {
        int cut = ribbons.size();
        for (int ribbon : ribbons) {
            cut += ribbon / x - 1;
        }
        return cut >= k;
    }
public:
    int maxLength(vector<int>& ribbons, int k) {
        int left = 1, right = *max_element(begin(ribbons), end(ribbons));
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isOK(ribbons, k, mid)) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return right;
    }
};