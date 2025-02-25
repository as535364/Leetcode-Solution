class Solution {
private:
    const int mod = 1e9 + 7;
public:
    int numOfSubarrays(vector<int>& arr) {
        // odd[i] end with idx i, number
        // even[i] end with idx i, number
        int n = arr.size();
        int odd = arr[0] & 1, even = (arr[0] & 1) == 0;
        int res = odd;
        for (int i = 1; i < arr.size(); ++i) {
            int prevOdd = odd, prevEven = even;
            if (arr[i] & 1) { // odd
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