class Solution {
private:
    vector<bool> isPrime;
    void calPrime(int n) {
        isPrime.resize(n + 1, true);
        isPrime[1] = false;
        for (int i = 2; i * i <= n; ++i) {
            if (isPrime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
    }
public:
    int primeSubarray(vector<int>& nums, int k) {
        calPrime(50000);

        int ans = 0, n = nums.size(), left = 0;
        int last = -1, last2 = -1;
        deque<int> maxDQ, minDQ;

        for (int i = 0; i < n; ++i) {
            int x = nums[i];
            if (isPrime[x]) {
                 last2 = last;
                last = i;
                // 入
                while (!minDQ.empty() && nums[minDQ.back()] >= x) {
                    minDQ.pop_back();
                }
                minDQ.push_back(i);

                while (!maxDQ.empty() && nums[maxDQ.back()] <= x) {
                    maxDQ.pop_back();
                }
                maxDQ.push_back(i);

                // 出
                while (nums[maxDQ.front()] - nums[minDQ.front()] > k) {
                    ++left;
                    if (left > maxDQ.front()) maxDQ.pop_front();
                    if (left > minDQ.front()) minDQ.pop_front();
                }

            }
            // 更新答案
            ans += last2 - left + 1;
        }
        return ans;
    }
};