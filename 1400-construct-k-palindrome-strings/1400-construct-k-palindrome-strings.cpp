class Solution {
public:
    bool canConstruct(string s, int k) {
        if (s.length() < k) return false;
        if (k > 26) return true;
        
        bitset<128> bs;
        for (char c : s) bs.flip(c);
        return bs.count() <= k;
    }
};