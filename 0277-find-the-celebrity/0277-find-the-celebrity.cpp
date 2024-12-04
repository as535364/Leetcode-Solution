/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        int candidate = 0;
        for (int i = 1; i < n; ++i) {
            if (knows(candidate, i)) {
                candidate = i;
            }
        }

        // to check theLastCandidate doesn't know any other
        for (int i = 0 ; i < n; ++i) {
            if (i == candidate) continue;
            if (knows(candidate, i)) return -1;
        }
        // to check everyone knows theLastCandidate
        for (int i = 0 ; i < n; ++i) {
            if (i == candidate) continue;
            if (!knows(i, candidate)) return -1;
        }
        
        return candidate;
    }
};