class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.size(), index1 = -1, index2 = -1;
        for (int i = 0; i < n; ++i) {
            if (s1[i] != s2[i]) {
                if (index1 == -1) index1 = i;
                else if (index2 == -1) index2 = i;
                else return false;
            }
        }
        if (index1 == -1 && index2 == -1) return true;
        else if (index1 != -1 && index2 == -1) return false;
        else return s1[index1] == s2[index2] && s1[index2] == s2[index1];
    }
};