//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    bool helper(vector<vector<char>>& mat, string& word, int i, int j, int N, int M, int index, vector<vector<bool>>& visited) {
        if (index == word.size()) return true;
    
        if (i < 0 || j < 0 || i >= N || j >= M || mat[i][j] != word[index] || visited[i][j]) {
            return false;
        }
        
        visited[i][j] = true;
    
        bool found = helper(mat, word, i + 1, j, N, M, index + 1, visited) ||
                     helper(mat, word, i - 1, j, N, M, index + 1, visited) ||
                     helper(mat, word, i, j + 1, N, M, index + 1, visited) ||
                     helper(mat, word, i, j - 1, N, M, index + 1, visited);
    
        visited[i][j] = false;
    
        return found;
    }
    
    bool isWordExist(vector<vector<char>>& mat, string& word) {
        int N = mat.size(), M = mat[0].size(); 

        vector<vector<bool>> visited(N, vector<bool>(M, false));
    
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (mat[i][j] == word[0] && helper(mat, word, i, j, N, M, 0, visited)) {
                    return true;
                }
            }
        }
    
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> mat(n, vector<char>(m, '*'));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];
        string word;
        cin >> word;
        Solution obj;
        bool ans = obj.isWordExist(mat, word);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends