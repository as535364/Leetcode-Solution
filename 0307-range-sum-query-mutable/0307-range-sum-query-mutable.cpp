class NumArray {
private:
    vector<int> tree, nums;
    int n;

    int prefixSum(int index) {
        int res = 0;
        for (int i = index; i > 0; i -= i & -i) {
            res += tree[i];
        }
        return res;
    }
public:
    NumArray(vector<int>& nums): n(nums.size()), nums(nums), tree(nums.size() + 1) {
        for (int i = 1; i <= n; ++i) {
            tree[i] += nums[i - 1];
            int nxt = i + (i & -i);
            if (nxt <= n) {
                tree[nxt] += tree[i];
            }
        }
    }
    
    void update(int index, int val) {
        int diff = val - nums[index];
        nums[index] = val;

        for (int i = index + 1; i <= n; i += i & -i) {
            tree[i] += diff;
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