class Solution {
private:
    int digitSum(int x) {
        int sum = x % 10;
        while (x /= 10) sum += x % 10;
        return sum;
    }
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, pair<int, int>> hashMap;
        for (int num : nums) {
            int digitS = digitSum(num);
            auto &pair = hashMap[digitS];
            if (num > pair.first) {
                pair.second = pair.first;
                pair.first = num;
            }
            else if (num > pair.second) {
                pair.second = num;
            }
        }
        int ans = -1;
        for (auto &[_, p] : hashMap){
            if (p.second == 0) continue;
            ans = max(ans, p.first + p.second);
        }
        return ans;
    }
};