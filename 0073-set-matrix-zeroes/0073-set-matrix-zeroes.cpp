class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int M = matrix.size(), N = matrix[0].size();
        int c0 = 1;

        for(int i = 0; i < M; ++i) {
            for(int j = 0; j < N; ++j) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    if(j == 0) c0 = 0;
                    else matrix[0][j] = 0;
                }
            }
        }

        for(int i = 1; i < M; ++i) {
            for(int j = 1; j < N; ++j) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0) 
                    matrix[i][j] = 0;
            }
        }

        if(c0 == 0) {
            for(int i = 0; i < M; ++i) {
                matrix[i][0] = 0;
            }
        }

        if(matrix[0][0] == 0) {
            for(int i = 0; i < N; ++i) {
                matrix[0][i] = 0; 
            }
        }
    }
};