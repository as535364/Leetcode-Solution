class NumArray {
private:
    vector<int> tree;
    int n;

    int prefixSum(int index) {
        int res = 0;
        while (index > 0) {
            res += tree[index];
            index -= index & -index;
        }
        return res;
    }
public:
    NumArray(vector<int>& nums): n(nums.size()) {
        tree.resize(n + 1);
        for (int i = 0; i < n; ++i) {
            update(i, nums[i]);
        }
    }
    
    void update(int index, int val) {
        int diff = val - sumRange(index, index);
        index++;
        while (index <= n) {
            tree[index] += diff;
            index += index & -index;
        }
    }
    
    int sumRange(int left, int right) {
        return prefixSum(right + 1) - prefixSum(left);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */