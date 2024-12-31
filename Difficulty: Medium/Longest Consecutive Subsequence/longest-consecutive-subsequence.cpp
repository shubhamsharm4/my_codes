//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
        int N = arr.size();
        sort(arr.begin(), arr.end());
        
        int currLen = 1;
        int maxLen = 0;
        
        for(int i = 1; i < N; ++i) {
            if(arr[i] != arr[i-1]) {
                if(arr[i] - arr[i-1] == 1) {
                    currLen += 1;
                }
                else if(arr[i] - arr[i-1] != 1) {
                    maxLen = max(maxLen, currLen);
                    currLen = 1;
                }
            }    
        }
        
        return max(maxLen, currLen);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.longestConsecutive(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends