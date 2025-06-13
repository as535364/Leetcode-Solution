class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();
        int left = 0, right = 1e9;
        sort(nums.begin(), nums.end());
        while(left < right){
            int mid = left + (right - left) / 2;
            int cnt = 0;
            for(int i = 1; i < n && cnt < p; ++i){
                if(nums[i] - nums[i - 1] <= mid){
                    ++cnt;
                    ++i;
                }
            }

            if(cnt >= p){
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        return left;        
    }
};