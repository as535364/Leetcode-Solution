class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>> pq;
        for(auto point : points){
            int x = point[0], y = point[1];
            int disSquare = x * x + y * y;
            pq.push({disSquare, x, y});
            if(pq.size() > k)pq.pop();
        }
        vector<vector<int>> res;
        while(!pq.empty()){
            int x = pq.top()[1], y = pq.top()[2];
            pq.pop();
            res.push_back({x, y});
        }
        return res;
    }
};