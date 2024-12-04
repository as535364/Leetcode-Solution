/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        unordered_set<int> candidate;
        for (int i = 0; i < n; ++i) {
            candidate.insert(i);
        }

        while (candidate.size() > 1) {
            int a = *candidate.begin();
            candidate.erase(a);
            int b = *candidate.begin();
            candidate.erase(b);
            if (knows(a, b)) {
                candidate.insert(b);
            }
            else {
                candidate.insert(a);
            }
        }

        int theLastCandidate = *candidate.begin();
        // to check theLastCandidate doesn't know any other
        for (int i = 0 ; i < n; ++i) {
            if (i == theLastCandidate) continue;
            if (knows(theLastCandidate, i)) return -1;
        }
        // to check everyone knows theLastCandidate
        for (int i = 0 ; i < n; ++i) {
            if (i == theLastCandidate) continue;
            if (!knows(i, theLastCandidate)) return -1;
        }
        
        return theLastCandidate;
    }
};