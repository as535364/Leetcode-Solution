class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> cnts(101);
        for (int num : nums) ++cnts[num];
        int maxFreq = *max_element(cnts.begin(), cnts.end());
        return count_if(cnts.begin(), cnts.end(), [&maxFreq](int v){ return v == maxFreq; }) * maxFreq;
    }
};