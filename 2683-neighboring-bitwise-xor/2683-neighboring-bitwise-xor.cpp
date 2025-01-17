class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int sum = accumulate(derived.begin(), derived.end(), 1);
        return sum & 1;
    }
};