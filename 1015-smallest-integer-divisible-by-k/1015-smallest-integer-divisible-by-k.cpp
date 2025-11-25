class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int remain = 1, cnt = 1;
        unordered_set<int> seenRemain(1);

        while (remain % k != 0) {
            remain = (remain * 10 + 1) % k;
            if (seenRemain.count(remain)) return -1;
            else seenRemain.insert(remain);
            ++cnt;
        }

        return cnt;
    }
};