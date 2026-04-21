struct UF {
public:
    UF (int n): n(n) {
        rank.resize(n + 1, 1);
        parent.resize(n + 1, 0);
    }

    int find(int x) {
        if (parent[x] == 0) return x;
        else return (parent[x] = find(parent[x]));
    }

    bool merge(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;

        if (rank[y] > rank[x]) swap(x, y);
        parent[y] = x;
        rank[x] += rank[y];
        return true;
    }
private:
    int n;
    vector<int> rank, parent;
};

class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        UF uf(n);
        for (const auto &allowedSwap : allowedSwaps) {
            int a = allowedSwap[0] + 1, b = allowedSwap[1] + 1;
            uf.merge(a, b);
        }

        unordered_map<int, unordered_map<int, int>> groupCnt;
        for (int i = 0; i < n; ++i) {
            ++groupCnt[uf.find(i + 1)][source[i]];
        }

        int min_ham = 0;
        for (int i = 0; i < n; ++i) {
            if (groupCnt[uf.find(i + 1)][target[i]] > 0) {
                --groupCnt[uf.find(i + 1)][target[i]];
            }
            else {
                ++min_ham;
            }
        }
        return min_ham;
    }
};