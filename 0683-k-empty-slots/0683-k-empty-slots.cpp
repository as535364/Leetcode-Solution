class Solution {
public:
    int kEmptySlots(vector<int>& bulbs, int k) {
        int n = bulbs.size();
        int maxNum = INT_MIN, minNum = INT_MAX;
        set<int> s;
        for (int i = 0; i < n; ++i) {
            int x = bulbs[i];
            s.insert(x);
            minNum = min(x, minNum);
            maxNum = max(x, maxNum);
            auto it1 = s.find(x), it2 = s.find(x);
            it1--; it2++;
            if (x != minNum && x - *(it1) == k + 1) return i + 1;
            if (x != maxNum && *(it2) - x == k + 1) return i + 1;
        }
        return -1;
    }
};