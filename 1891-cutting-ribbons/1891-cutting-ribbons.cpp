class Solution {
private:
    bool isOK(const vector<int> &ribbons, int k, int x) {
        int cut = 0;
        for (int ribbon : ribbons) {
            cut += ribbon / x;
            if (cut >= k) return true;
        }
        return false;
    }
public:
    int maxLength(vector<int>& ribbons, int k) {
        int left = 1, right = *max_element(begin(ribbons), end(ribbons));
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isOK(ribbons, k, mid)) {
                cout << mid << endl;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return right;
    }
};