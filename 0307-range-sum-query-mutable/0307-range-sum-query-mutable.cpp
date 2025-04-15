class NumArray {
public:
    NumArray(vector<int>& nums) {
        bit.resize(nums.size() + 1);
        n = nums.size();
        for(int i = 0; i < n; ++i){
            add(i + 1, nums[i]);
        }
    }
    
    void update(int index, int val) {
        int diff = val - sumRange(index, index);
        add(index + 1, diff);
    }
    
    int sumRange(int left, int right) {
        return sum(right + 1) - sum(left);
    }
    int lowbit(int x){
        return x & -x;
    }
    int sum(int idx){
        int res = 0;
        for(int i = idx; i > 0; i -= lowbit(i)){
            res += bit[i];
        }
        return res;
    }
    void add(int idx, int val){
        for(int i = idx; i <= n; i += lowbit(i)){
            bit[i] += val;
        }
    }
    int n;
    vector<int> bit;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */