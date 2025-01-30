//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool isSafe(vector<int>& board, int row, int col) {
    	for(int i = 0; i < row; ++i) {
    		if(board[i] == col || abs(board[i] - col) == abs(i - row)) 
    			return false;
    	}
    	return true;
    }
    
    void solve(vector<int>& board, int N, int row, vector<vector<int>>& res) {
    	if(row == N) {
    		res.push_back(board);
    		return;
    	}
    
    	for(int col = 0; col < N; ++col) {
    		if(isSafe(board, row, col)) {
    			board[row] = col;
    			solve(board, N, row+1, res);
    			board[row] = -1;
    		}
    	}
    }
    
    vector<vector<int>> nQueen(int N) {
    	vector<vector<int>> res;
    	vector<int> board(N, -1);
    	solve(board, N, 0, res); 
    	
    	for(int i = 0; i < res.size(); i++) {
            for(int j = 0; j < res[i].size(); j++) {
                res[i][j] += 1;
            }
        }
    	return res; 
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if (ans.size() == 0)
            cout << -1 << "\n";
        else {
            sort(ans.begin(), ans.end());
            for (int i = 0; i < ans.size(); i++) {
                cout << "[";
                for (int u : ans[i])
                    cout << u << " ";
                cout << "] ";
            }
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends