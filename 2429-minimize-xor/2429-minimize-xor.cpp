class Solution {
private:
    const static int maxBit = 31;
public:
    int minimizeXor(int num1, int num2) {
        bitset<maxBit> num1bit(num1), numXorBit;
        int nums2BitCount = __builtin_popcount(num2);
        for (int i = maxBit - 1; i >= 0; --i) {
            if (num1bit[i] && nums2BitCount-- > 0) {
                numXorBit[i] = true;
            }
            if (nums2BitCount <= 0) break;
        }
        if (nums2BitCount <= 0) return numXorBit.to_ulong();

        for (int i = 0 ; i < maxBit; ++i) {
            if (!numXorBit[i] && nums2BitCount-- > 0) {
                numXorBit[i] = true;
            }
            if (nums2BitCount <= 0) break;
        }
        return numXorBit.to_ulong(); 
    }
};