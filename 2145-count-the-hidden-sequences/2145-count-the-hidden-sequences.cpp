class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long minDiff = numeric_limits<long long>::max();
        long long maxDiff = numeric_limits<long long>::min();

        long long pre = 0;
        for (int d : differences) {
            pre += d;
            maxDiff = max(maxDiff, pre);
            minDiff = min(minDiff, pre);
        }
        long long minStart = max((long long)lower, lower - minDiff);
        long long maxStart = min((long long)upper, upper - maxDiff);
        return max(0LL, maxStart - minStart + 1);
    }
};
// 1, -2, 2
// first: 4
// first: 3

// 3, -1, 4, 5, 3
// first: 0
// first: -3

// 4, -3, 1
// first: 2
// first: 6

// -40
// first: -6
// first: 53