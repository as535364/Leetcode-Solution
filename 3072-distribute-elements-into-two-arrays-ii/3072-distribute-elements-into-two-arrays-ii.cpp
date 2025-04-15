class BIT {
private:
    int n;
    vector<int> tree;
public:
    BIT (int n): n(n), tree(n + 1) {}

    void add(int idx) {
        for (int i = idx; i <= n; i += i & -i) {
            tree[i] += 1;
        }
    }
    int prefixSum(int idx) {
        int res = 0;
        for (int i = idx; i > 0; i -= i & -i) {
            res += tree[i];
        }
        return res;
    }
};

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> tmp(nums);
        sort(tmp.begin(), tmp.end());
        tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
        int maxN = tmp.size();

        BIT bit1(maxN), bit2(maxN);
        vector<int> arr1({nums[0]}), arr2({nums[1]});
        bit1.add(lower_bound(tmp.begin(), tmp.end(), nums[0]) - tmp.begin() + 1);
        bit2.add(lower_bound(tmp.begin(), tmp.end(), nums[1]) - tmp.begin() + 1);

        for (int i = 2; i < nums.size(); ++i) {
            int rank = lower_bound(tmp.begin(), tmp.end(), nums[i]) - tmp.begin() + 1;
            int greaterCount1 = arr1.size() - bit1.prefixSum(rank);
            int greaterCount2 = arr2.size() - bit2.prefixSum(rank);
            cout << rank << endl;
            cout << bit1.prefixSum(rank) << ' ' << bit2.prefixSum(rank) << endl;
            cout << greaterCount1 << ' ' << greaterCount2 << endl;

            if (greaterCount1 > greaterCount2 || (greaterCount1 == greaterCount2 && arr1.size() <= arr2.size())) {
                arr1.push_back(nums[i]);
                bit1.add(rank);
            }
            else {
                arr2.push_back(nums[i]);
                bit2.add(rank);
            }
        }
        arr1.insert(arr1.end(), arr2.begin(), arr2.end());
        return arr1;
    }
};