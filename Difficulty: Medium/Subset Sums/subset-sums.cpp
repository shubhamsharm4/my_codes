//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<vector<int>> ans;
    void helper(vector<int>& arr, int i, vector<int>& curr) {
        if(i == arr.size()) {
            ans.push_back(curr);
            return;
        }
        
        curr.push_back(arr[i]);
        helper(arr, i+1, curr);
        curr.pop_back();
        helper(arr, i+1, curr);
    }
    
    vector<int> subsetSums(vector<int>& arr) {
        vector<int> curr;
        helper(arr, 0, curr);
        
        vector<int> res; 
        for(auto it : ans) {
            int s = 0;
            for(int i : it) s += i;
            res.push_back(s);
        }
        
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t; // Number of test cases
    cin >> t;
    cin.ignore(); // Ignore the newline after the integer input

    while (t--) {
        vector<int> inputArray;
        string inputLine;

        // Input format: first number n followed by the array elements
        getline(cin, inputLine);
        stringstream inputStream(inputLine);
        int num;
        while (inputStream >> num) {
            inputArray.push_back(num); // Read the array elements from input string
        }

        Solution solutionObject;
        vector<int> result = solutionObject.subsetSums(inputArray);
        sort(result.begin(), result.end());

        for (int i = 0; i < result.size(); i++) {
            if (i != 0)
                cout << " ";
            cout << result[i];
        }
        cout
            << endl
            << "~\n"; // Print results in list format with new line after each test case
    }

    return 0;
}

// } Driver Code Ends