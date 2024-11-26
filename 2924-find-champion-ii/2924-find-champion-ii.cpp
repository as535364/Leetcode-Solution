class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        unordered_set<int> champion;
        for (int i = 0; i < n; ++i) champion.insert(i);

        for (const auto &edge : edges) {
            auto it = champion.find(edge[1]);
            if (it != champion.end()) {
                champion.erase(it);
            }
        }

        if (champion.size() == 1) return *champion.begin();
        else return -1;
    }
};