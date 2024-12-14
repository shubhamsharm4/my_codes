class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int M = board.size(), N = board[0].size();
        vector<int> rDir = {1, 0, -1, 0, -1, 1, 1, -1};
        vector<int> cDir = {0, 1, 0, -1, -1, 1, -1, 1};
        
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                int aliveN = 0;
                
                for (int k = 0; k < 8; ++k) {
                    int nRow = i + rDir[k];
                    int nCol = j + cDir[k];
                    
                    if (nRow >= 0 && nRow < M && nCol >= 0 && nCol < N && 
                        abs(board[nRow][nCol]) == 1) {
                        aliveN++;
                    }
                }
                
                if (board[i][j] == 1 && (aliveN < 2 || aliveN > 3)) {
                    board[i][j] = -1; 
                }
                if (board[i][j] == 0 && aliveN == 3) {
                    board[i][j] = 2; 
                }
            }
        }
        
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (board[i][j] == -1) board[i][j] = 0; 
                if (board[i][j] == 2) board[i][j] = 1;  
            }
        }
    }
};
