class DSU {
private:
    vector<int> size, parent;
public:
    DSU (int n): size(n), parent(n, -1) {}
    int find(int x) {
        if (parent[x] == -1) return x;
        return parent[x] = find(parent[x]);
    }
    
    bool merge(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        if (size[x] < size[y]) swap(x, y);
        parent[y] = x;
        size[x] += size[y];
        return true;
    }
};

class Solution {
private:
    int maxIdx = 1;
    unordered_map<string, int> word2Id;
public:
    bool areSentencesSimilarTwo(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        if (sentence1.size() != sentence2.size()) return false;
        
        for (string &s : sentence1) {
            if (word2Id.find(s) == word2Id.end()) {
                word2Id[s] = maxIdx++;
            }
        }
        
        for (string &s : sentence2) {
            if (word2Id.find(s) == word2Id.end()) {
                word2Id[s] = maxIdx++;
            }
        }
        
        for (const auto& sp : similarPairs) {
            const string &s1 = sp[0], &s2 = sp[1];
            if (word2Id.find(s1) == word2Id.end()) {
                word2Id[s1] = maxIdx++;
            }
            if (word2Id.find(s2) == word2Id.end()) {
                word2Id[s2] = maxIdx++;
            }
        }
        
        DSU dsu(maxIdx);
        for (const auto& sp : similarPairs) {
            const string &s1 = sp[0], &s2 = sp[1];
            int id1 = word2Id[s1], id2 = word2Id[s2];
            dsu.merge(id1, id2);
        }
        
        int n = sentence1.size();
        for (int i = 0; i < n; ++i) {
            const string &s1 = sentence1[i], &s2 = sentence2[i];
            int id1 = word2Id[s1], id2 = word2Id[s2];
            if (dsu.find(id1) != dsu.find(id2)) return false;
        }
        return true;
    }
};