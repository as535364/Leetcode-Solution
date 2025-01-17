class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        bool last = 1;
        for (int d : derived) {
            last ^= d;
        }
        return last;
    }
};