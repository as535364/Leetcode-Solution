class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int, int> counts;
        for (int h : hand) ++counts[h];
        for (auto [num, count] : counts) {
            if (count == 0) continue;
            while (count--) {
                for (int i = 1; i < groupSize; ++i) {
                    if (counts.find(num + i) == counts.end() || counts[num + i] == 0) {
                        return false;
                    }
                    --counts[num + i];
                }
            }
        }
        return true;
    }
};