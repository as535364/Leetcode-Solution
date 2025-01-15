class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l = 0, r = arr.size() - 1;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (arr[m] > arr[m + 1]) { // right part
                r = m;
            }
            else { // left part
                l = m + 1;
            }
        }
        return l;
    }
};

// 0 1 2 3 2
// 0 1 2 3 4
