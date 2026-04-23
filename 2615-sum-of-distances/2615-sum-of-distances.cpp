class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> hashMap;
        unordered_map<int, vector<long long>> hashMapPrefixsum;
        
        for(int i = 0; i < n; ++i){
            int num = nums[i];
            hashMap[num].emplace_back(i);
        }
        for(auto &[k, v] : hashMap){
            long long prefixSum = 0;
            for(int val : v){
                prefixSum += val;
                hashMapPrefixsum[k].emplace_back(prefixSum);
            }
        }
        // for(auto &[k, v] : hashMapPrefixsum){
        //     cout << k << endl;
        //     for(long long val : v){
        //         cout << val << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;
        
        vector<long long> ans;
        for(long long i = 0; i < n; ++i){
            long long nowSum = 0, val = nums[i];
            if(hashMap[val].size() > 1){
                long long idxInPrefix = lower_bound(hashMap[val].begin(), hashMap[val].end(), i) - hashMap[val].begin();
                // cout << i * (idxInPrefix + 1) - hashMapPrefixsum[val][idxInPrefix] << " ";
                // cout << hashMapPrefixsum[val].back() - hashMapPrefixsum[val][idxInPrefix] - (hashMapPrefixsum[val].size() - idxInPrefix - 1) * i << endl;
                nowSum += i * (idxInPrefix + 1) - hashMapPrefixsum[val][idxInPrefix];
                nowSum += hashMapPrefixsum[val].back() - hashMapPrefixsum[val][idxInPrefix] - (hashMapPrefixsum[val].size() - idxInPrefix - 1) * i;
            }
            ans.emplace_back(nowSum);
        }
        return ans;
    }
};