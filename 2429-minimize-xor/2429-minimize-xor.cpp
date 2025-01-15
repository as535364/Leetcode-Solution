class Solution {
private:
    const static int maxBit = 31;
public:
    int minimizeXor(int num1, int num2) {
        bitset<maxBit> num1bit(num1), num2bit(num2), numXorBit;
        int nums2BitCount = num2bit.count();
        for (int i = maxBit - 1; i >= 0; --i) {
            if (num1bit[i] && nums2BitCount-- > 0) {
                numXorBit[i] = true;
            }
        }
        if (nums2BitCount <= 0) return numXorBit.to_ulong();

        for (int i = 0 ; i < maxBit; ++i) {
            if (!numXorBit[i] && nums2BitCount-- > 0) {
                numXorBit[i] = true;
            }
        }
        return numXorBit.to_ulong(); 
    }
};