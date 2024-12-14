class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int N = matrix.size();
        int M = matrix[0].size();
        
        vector<bool> row(N, false), col(M, false);

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (matrix[i][j] == 0) {
                    row[i] = true;
                    col[j] = true;
                }
            }
        }

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (row[i] || col[j]) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};