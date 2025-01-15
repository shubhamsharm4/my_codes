//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        int N = arr.size(); 
        int maxLen = 0;
        
        unordered_map<int,int> mp;
        
        int curr = 0;
        
        for(int i = 0; i < N; ++i) {
            curr += arr[i];
            
            if(curr == k) maxLen = i + 1;
            
            else if(mp.find(curr - k) != mp.end()) {
                maxLen = max(maxLen, i - mp[curr - k]);
            }
            
            if(mp.find(curr) == mp.end()) mp[curr] = i;
        }
        
        return maxLen; 
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution solution;
        cout << solution.longestSubarray(arr, k) << "\n";
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends