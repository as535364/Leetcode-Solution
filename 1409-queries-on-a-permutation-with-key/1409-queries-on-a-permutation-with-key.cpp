class BIT {
private:
    vector<int> tree;
public:
    BIT (int n): tree(n + 1) {}
    int pre(int i) {
        int res = 0;
        for (; i; i -= i & -i) {
            res += tree[i];
        }
        return res;
    }
    void update(int i, int diff) {
        for (; i < tree.size(); i += i & -i) {
            tree[i] += diff;
        }
    }
};
class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        int qLen = queries.size();
        BIT bit(m + qLen);
        vector<int> pos(m + 1);

        // _ _ _ _ _ 1 2 3 4 5 6 7
        for (int i = 1; i <= m; ++i) {
            pos[i] = qLen + i - 1;
            bit.update(qLen + i, 1);
        }

        vector<int> res;
        int lastIdx = qLen - 1;
        for (int q : queries) {
            int p = pos[q];
            res.push_back(bit.pre(p));

            bit.update(p + 1, -1);
            pos[q] = lastIdx--;
            bit.update(pos[q] + 1, 1);
        }
        return res;
    }
};