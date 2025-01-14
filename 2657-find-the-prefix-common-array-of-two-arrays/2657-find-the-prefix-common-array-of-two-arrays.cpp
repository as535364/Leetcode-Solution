class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> C(n), count(n + 1);
        C[0] = (A[0] == B[0]);
        count[A[0]]++, count[B[0]]++;

        for (int i = 1; i < n; ++i) {
            C[i] = C[i - 1];
            if (A[i] == B[i]) C[i]++;
            else {
                if (++count[A[i]] == 2) C[i]++;
                if (++count[B[i]] == 2) C[i]++;
            }
        }
        return C;
    }
};