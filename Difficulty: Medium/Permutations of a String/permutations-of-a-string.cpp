//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void helper(string& s, set<string>& res, int index, int N) {
        if(index == N) {
            res.insert(s);
            return; 
        }
        
        for(int i = index; i < N; ++i) {
            swap(s[index], s[i]);
            helper(s, res, index + 1, N);
            swap(s[index], s[i]); 
        }
    }
    vector<string> findPermutation(string &s) {
        int N = s.length();
        set<string> res; 
        
        helper(s, res, 0, N);
        
        vector<string> ans;
        for(auto it : res) ans.push_back(it);
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        vector<string> ans = ob.findPermutation(S);
        sort(ans.begin(), ans.end());
        for (auto i : ans) {
            cout << i << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends