class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int candiesGet = 0;
        queue<int> boxes;

        for (int box : initialBoxes) {
            boxes.push(box);
        }

        bool change = true;
        while (!boxes.empty() && change) {
            int n = boxes.size();
            change = false;
            for (int i = 0; i < n; ++i) {
                int nowBoxID = boxes.front();
                boxes.pop();

                if (!status[nowBoxID]) {
                    boxes.push(nowBoxID);
                    continue;
                }
                candiesGet += candies[nowBoxID];
                for (int containedBoxID : containedBoxes[nowBoxID]) {
                    boxes.push(containedBoxID);
                }
                for (int key : keys[nowBoxID]) {
                    status[key] = 1;
                }
                change = true;
            }
        }
        return candiesGet;
    }
};