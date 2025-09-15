class Solution {
public:
    int maxXorSubsequences(vector<int>& nums) {
        // X ^ Y means each element in nums can be used for 0, 1, 2 times
        // consider about an array nums * 2
        // using twice means using zero times
        // so just consider about nums
        // Gaussian Elimination?
        int maxXOR = 0;
        
        while (true) {
            // 1. 找出目前陣列中的最大值。
            int currentMax = nums.empty() ? 0 : *std::max_element(nums.begin(), nums.end());
            
            // 2. 如果最大值為 0，表示所有數字都已被處理完畢，結束迴圈。
            if (currentMax == 0) {
                return maxXOR;
            }
            
            // 3. 貪婪地更新目前的最大 XOR 和。
            //    嘗試將當前的最大元素 currentMax 加入 XOR 運算，如果能讓結果變大就更新。
            maxXOR = std::max(maxXOR, maxXOR ^ currentMax);
            
            // 4. 使用 currentMax 來「消去」陣列中其他數字的位元。
            //    這是高斯消去法的核心步驟，目的是讓陣列中的數字逐漸變小，最終趨近於 0。
            for (int& num : nums) {
                num = std::min(num, num ^ currentMax);
            }
        }
        return maxXOR;
    }
};