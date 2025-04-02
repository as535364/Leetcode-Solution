class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size(), k = costs[0].size();
        if (n == 1) return *min_element(costs[0].begin(), costs[0].end());

        int prevMinColor = -1, prevMinCost = INT_MAX, prevSecondCost = INT_MAX;

        for (int j = 0; j < k; ++j) {
            if (prevMinColor == -1 || prevMinCost > costs[0][j]) {
                prevSecondCost = prevMinCost;
                prevMinCost = costs[0][j];
                prevMinColor = j;
            }
            else if (prevSecondCost > costs[0][j]) {
                prevSecondCost = costs[0][j];
            }
        }

        for (int i = 1; i < n; ++i) {
            int minColor = -1, minCost = INT_MAX, secondCost = INT_MAX;
            for (int j = 0; j < k; ++j) {
                int cost = (prevMinColor == j ? prevSecondCost : prevMinCost) + costs[i][j];
                
                if (minColor == -1 || minCost > cost) {
                    secondCost = minCost;
                    minCost = cost;
                    minColor = j;
                }
                else if (secondCost > cost) {
                    secondCost = cost;
                }
            }
            prevMinCost = minCost;
            prevMinColor = minColor;
            prevSecondCost = secondCost;
        }
        return prevMinCost;
    }
};