class Solution {
private:
    const int mod = 1e9 + 7;
public:
    int numOfSubarrays(vector<int>& arr) {
        // odd[i] end with idx i, number
        // even[i] end with idx i, number
        int n = arr.size();
        int odd = 0, even = 0, res = 0;
        for (int num : arr) {
            int prevOdd = odd, prevEven = even;
            if (num & 1) { // odd
                odd = (prevEven + 1) % mod;
                even = prevOdd;
            }
            else {
                even = (prevEven + 1) % mod;
            }
            res = (res + odd) % mod;
        }
        return res;
    }
};