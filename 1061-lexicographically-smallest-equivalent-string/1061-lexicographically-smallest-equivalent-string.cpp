class DSU {
private:
    vector<int> parent;
public:
    DSU (int n): parent(n, -1) {}
    int find(int x) {
        if (parent[x] == -1) return x;
        return parent[x] = find(parent[x]);
    }
    void merge(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return;
        if (x > y) swap(x, y);
        parent[y] = x;
    }
};

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        DSU dsu(26);
        for (int i = 0; i < s1.length(); ++i) {
            dsu.merge(s1[i] - 'a', s2[i] - 'a');
        }

        for (int i = 0; i < baseStr.length(); ++i) {
            baseStr[i] = dsu.find(baseStr[i] - 'a') + 'a';
        }
        return baseStr;
    }
};