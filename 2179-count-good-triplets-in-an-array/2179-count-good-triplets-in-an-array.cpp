class BIT {
private:
    vector<int> tree;
public:
    BIT (int n): tree(n + 1) {}

    void update(int i, int diff) {
        for (; i < tree.size(); i += i & -i) {
            tree[i] += diff;
        }
    }

    int pre(int i) {
        int res = 0;
        for (; i; i -= i & -i) {
            res += tree[i];
        }
        return res;
    }
};

class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> p(n);
        for (int i = 0; i < n; ++i) {
            p[nums1[i]] = i;
        }
        
        BIT bit(n);
        long long res = 0;

        for (int i = 0; i < n; ++i) {
            int y = p[nums2[i]];
            int less = bit.pre(y);
            res += (long long)(less) * (n - 1 - y - i + less); 
            bit.update(y + 1, 1);
        }
        return res;
    }
};