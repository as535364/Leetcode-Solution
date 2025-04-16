class BIT {
private:
    vector<int> tree;
    int pre(int i) {
        int res = 0;
        for (; i > 0; i -= i & -i) {
            res += tree[i];
        }
        return res;
    }
public:
    BIT (int n): tree(n + 1) {}
    void update(int i, int diff) {
        for (; i < tree.size(); i += i & -i) {
            tree[i] += diff;
        }
    }
    int query(int l, int r) {
        if (l > r) return 0;
        return pre(r) - pre(l - 1);
    }
};

class Solution {
public:
    vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        BIT bit(n - 1);

        auto update = [&](int idx, int diff) {
            if (nums[idx - 1] < nums[idx] && nums[idx] > nums[idx + 1]) {
                bit.update(idx, diff);
            }
        };

        for (int i = 1; i < n - 1; ++i) {
            update(i, 1);
        }


        vector<int> res;
        for (const auto &q :queries) {
            int type = q[0], x = q[1], y = q[2];
            if (type == 1) {
                res.push_back(bit.query(x + 1, y - 1));
                continue;
            }

            for (int i = max(x - 1, 1); i <= min(x + 1, n - 2); ++i) {
                update(i, -1);
            }
            nums[x] = y;
            for (int i = max(x - 1, 1); i <= min(x + 1, n - 2); ++i) {
                update(i, 1);
            }
        }
        return res;
    }
};