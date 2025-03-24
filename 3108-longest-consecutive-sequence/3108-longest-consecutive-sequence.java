class Solution {
    public int longestConsecutive(int[] nums) {
        HashMap<Integer, Integer> conseqMap = new HashMap<>();
        int max = 0;

        for (int num : nums) {
            if (!conseqMap.containsKey(num)) {
                
                int left = conseqMap.getOrDefault(num - 1, 0);
                int right = conseqMap.getOrDefault(num + 1, 0);
                int length = left + right + 1;

                conseqMap.put(num - left, length);
                conseqMap.put(num + right, length);
                // conseqMap.put(num, length);

                max = Math.max(max, length);
            }
        }


        return max;
    }
}