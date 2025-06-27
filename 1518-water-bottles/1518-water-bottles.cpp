class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int res = numBottles, emptyBottles = numBottles;
        
        while (emptyBottles / numExchange) {
            res += emptyBottles / numExchange;
            emptyBottles = emptyBottles / numExchange + emptyBottles % numExchange;
        }
        return res;
    }
};