/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        
        int l = 0, r = n - 1;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (mountainArr.get(m) > mountainArr.get(m + 1)) { // right part
                r = m;
            }
            else { // left part
                l = m + 1;
            }
        }
        
        int peakIdx = l;
        
        // find 0 ~ peakIdx, increase
        l = 0, r = peakIdx;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (mountainArr.get(m) >= target) {
                r = m;
            }
            else { // left part
                l = m + 1;
            }
        }
        if (mountainArr.get(l) == target) return l;
            
        // find peakIdx ~ n - 1, decrease
        l = peakIdx, r = n - 1;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (mountainArr.get(m) <= target) {
                r = m;
            }
            else { // left part
                l = m + 1;
            }
        }
        if (mountainArr.get(l) == target) return l;
        return -1;
    }
};