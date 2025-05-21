class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        bool rowZero = false, colZero = false;
        // set<int> rows, columns;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(!matrix[i][j]){
                    // rows.insert(i);
                    // columns.insert(j);
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                    if(i == 0)rowZero = true;
                    if(j == 0)colZero = true;
                }
            }
        }
        for(int i = 1; i < m; ++i){
            for(int j = 1; j < n; ++j){
                if(!matrix[i][0] || !matrix[0][j]){ // rows.count(i) || columns.count(j)
                    matrix[i][j] = 0;
                }
            }
        }
        if(rowZero){
            for(int j = 0; j < n; ++j)matrix[0][j] = 0;
        }
        if(colZero){
            for(int i = 0; i < m; ++i)matrix[i][0] = 0;
        }
    }
};