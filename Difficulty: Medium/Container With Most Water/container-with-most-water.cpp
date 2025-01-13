//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {

  public:
    int maxWater(vector<int> &arr) {
        int N = arr.size();
        int maxi = 0;
        
        int l = 0, r = N - 1;
        while(l < r) {
            int curr = min(arr[l], arr[r]) * (r - l);
            maxi = max(maxi, curr);
            if(arr[l] < arr[r]) l++;
            else r--;
        }
        
        return maxi; 
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
        int res = ob.maxWater(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends