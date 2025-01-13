//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        int N = s.length();
        int maxLen = 0; 
        
        vector<bool> vis(26, false); 
        int l = 0, r = 0;
        
        while(r < N) {
            while(vis[s[r] - 'a'] == true) {
                vis[s[l] - 'a'] = false;
                l++;
            }
            
            vis[s[r] - 'a'] = true;
            maxLen = max(maxLen, r - l + 1);
            r++;
        }
        
        return maxLen; 
        
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        Solution obj;
        string s;
        cin >> s;
        cout << obj.longestUniqueSubstr(s) << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends