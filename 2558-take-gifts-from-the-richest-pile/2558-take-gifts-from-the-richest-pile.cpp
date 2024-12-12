class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long sum = accumulate(gifts.begin(), gifts.end(), 0LL);
        priority_queue<int> pq;
        for (int g : gifts) pq.push(g);
        while (k--) {
            int most = pq.top();
            int remain = sqrt(most);
            pq.pop();
            pq.push(remain);
            sum -= most - remain;
        }
        return sum;
    }
};