class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int last = 0;
        for (int i = 0; i < derived.size(); ++i) {
            last ^= derived[i];
        }
        return last == 0;
    }
};