/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        unordered_map<int, unordered_map<int, bool>> cache;
        int candidate = 0;
        for (int i = 1; i < n; ++i) {
            if (knows(candidate, i)) {
                cache[candidate][i] = true;
                candidate = i;
            }
            else {
                cache[candidate][i] = false;
            }
        }

        // to check theLastCandidate doesn't know any other
        for (int i = 0 ; i < n; ++i) {
            if (i == candidate) continue;
            if ((cache[candidate].count(i) && cache[candidate][i]) || knows(candidate, i)) return -1;
        }
        // to check everyone knows theLastCandidate
        for (int i = 0 ; i < n; ++i) {
            if (i == candidate) continue;
            if ((cache[i].count(candidate) && !cache[i][candidate]) || !knows(i, candidate)) return -1;
        }
        
        return candidate;
    }
};