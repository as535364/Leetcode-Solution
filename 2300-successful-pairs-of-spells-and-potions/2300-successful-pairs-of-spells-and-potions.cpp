class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size(), m = potions.size();
        sort(potions.begin(), potions.end());

        vector<pair<int, int>> spellsSort(n);
        for (int i = 0; i < n; ++i) {
            spellsSort[i] = {spells[i], i};
        }
        sort(spellsSort.begin(), spellsSort.end(), greater<>());


        vector<int> ans(n);
        int j = 0;
        for (int i = 0; i < n; ++i) {
            while (j < m && static_cast<long long>(spellsSort[i].first) * static_cast<long long>(potions[j]) < success) {
                ++j;
            }
            ans[spellsSort[i].second] = m - j;
        }
        return ans;
    }
};