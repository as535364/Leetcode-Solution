class FindSumPairs {
private:
    unordered_map<int, int> nums2Cnts;
    vector<int> nums1, nums2;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2): nums1(nums1), nums2(nums2) {
        for (int num : nums2) ++nums2Cnts[num];
    }
    
    void add(int index, int val) {
        --nums2Cnts[nums2[index]];
        nums2[index] += val;
        ++nums2Cnts[nums2[index]];
    }
    
    int count(int tot) {
        int res = 0;
        for (int num : nums1) {
            int rest = tot - num;
            if (nums2Cnts.count(rest) == 0) continue;
            res += nums2Cnts[rest];
        }
        return res;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */