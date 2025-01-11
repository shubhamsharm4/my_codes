//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestUniqueSubstring(string &s) {
        int maxLen = 0;
        
        vector<bool> vis(26,false);
        int l = 0, r = 0;
        
        while(r < s.length()) {
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
        string str;
        cin >> str;
        Solution ob;
        cout << ob.longestUniqueSubstring(str) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends