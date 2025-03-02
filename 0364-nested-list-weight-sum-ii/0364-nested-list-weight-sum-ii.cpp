/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
private:
    vector<int> val, weight;
    void dfs(int depth, NestedInteger& n) {
        if (n.isInteger()) {
            val.push_back(n.getInteger());
            weight.push_back(depth);
        }
        else {
            for (NestedInteger &nn : n.getList()) {
                dfs(depth + 1, nn);
            }
        }
    }
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        for (NestedInteger &nn : nestedList) {
            dfs(1, nn);
        }
        int maxDepth = *max_element(weight.begin(), weight.end());
        for (int &d : weight) d = maxDepth - d + 1;
        
        int sum = 0;
        for (int i = 0; i < val.size(); ++i) {
            sum += val[i] * weight[i];
        }
        return sum;
    }
};