//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxLen(vector<int> &arr) {
        int maxLen = 0;
        
        unordered_map<int,int>mp;
        
        int presum = 0;
        
        for(int i = 0; i < arr.size(); ++i) {
            presum += (arr[i] == 0) ? -1 : 1;
            
            if(presum == 0) maxLen = i + 1;
            
            if(mp.find(presum) != mp.end()) maxLen = max(maxLen, i - mp[presum]);
            
            else mp[presum] = i;
        }
        
        return maxLen; 
    }
};


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    cin.ignore(); // To ignore the newline character after reading T

    while (T--) {
        string line;
        getline(cin, line); // Read the whole line for the array

        // Convert the line into an array of integers
        stringstream ss(line);
        vector<int> a;
        int num;
        while (ss >> num) {
            a.push_back(num);
        }

        // Create the solution object
        Solution obj;

        // Call the maxLen function and print the result
        cout << obj.maxLen(a) << endl;
    }

    return 0;
}
// } Driver Code Ends