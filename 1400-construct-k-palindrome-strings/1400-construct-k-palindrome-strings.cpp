class Solution {
public:
    bool canConstruct(string s, int k) {
        if (s.length() < k) return false;
        
        bitset<128> bs;
        for (char c : s) bs.flip(c);
        return bs.count() <= k;
    }
};