class BIT {
private:
    vector<int> tree;
public:
    BIT(int n): tree(n + 1) {}
    void add(int i) {
        for (; i < tree.size(); i += i & -i) {
            tree[i] += 1;
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
private:
    const int MOD = 1e9 + 7;
public:
    int createSortedArray(vector<int>& instructions) {
        int inserted = 0, res = 0;
        BIT bit(1e5);

        for (int num : instructions) {
            int lessCount = bit.pre(num - 1);
            int greaterCount = inserted - bit.pre(num);
            res = (res + min(lessCount, greaterCount)) % MOD;

            inserted++;
            bit.add(num);
        }
        return res;
    }
};