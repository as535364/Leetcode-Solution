class Solution {
private:
    unordered_set<string> allPossibilities;
    void dfs(int idx, string now, const string &tiles) {
        if (idx == tiles.size()) {
            allPossibilities.insert(now);
            return;
        }
        now += tiles[idx];
        dfs(idx + 1, now, tiles);
        now.pop_back();
        dfs(idx + 1, now, tiles);
    }
public:
    int numTilePossibilities(string tiles) {
        sort(tiles.begin(), tiles.end());
        do {
            string tmp;
            dfs(0, tmp, tiles);
        } while (next_permutation(tiles.begin(), tiles.end()));
        return allPossibilities.size() - 1;
    }
};