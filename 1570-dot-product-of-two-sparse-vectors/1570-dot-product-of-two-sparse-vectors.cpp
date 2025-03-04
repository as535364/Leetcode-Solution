class SparseVector {
public:
    vector<pair<int, int>> arr;
    SparseVector(vector<int> &nums) {
        for (int i = 0; i < nums.size(); ++i) {
            if (!nums[i]) continue;
            else arr.push_back({i, nums[i]});
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int dotSum = 0;
        int i = 0, j = 0;
        while (i < arr.size() && j < vec.arr.size()) {
            if (arr[i].first == vec.arr[j].first) {
                dotSum += arr[i].second * vec.arr[j].second;
                ++i, ++j;
            }
            else if (arr[i].first < vec.arr[j].first) {
                ++i;
            }
            else {
                ++j;
            }
        }
        return dotSum;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);