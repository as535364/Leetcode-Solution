class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int ans = 0;
        for (int fruitNum : fruits) {
            bool placed = false;
            for (int &basketCapacity : baskets) {
                if (basketCapacity >= fruitNum) {
                    placed = true;
                    basketCapacity = 0;
                    break;
                }
            }
            ans += !placed;
        }
        return ans;
    }
};