//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find equilibrium point in the array.
    int findEquilibrium(vector<int> &arr) {
        int N = arr.size();
        vector<int> v(N);
        
        v[0] = arr[0];
        for(int i = 1; i < N; ++i) {
            v[i] = v[i-1] + arr[i]; 
        }
        
        vector<int> s(N);
        s[N-1] = arr[N-1];
        
        for(int i = N-2; i >= 0; --i) {
            s[i] = s[i+1] + arr[i];
        }
        
        for(int i = 0; i < N; ++i) {
            if(s[i] == v[i]) return i; 
        }
        
        return -1; 
        
        //1 3 3 6
        //6 5 3 3 
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To discard any leftover newline characters
    while (t--)   // while testcases exist
    {
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.findEquilibrium(arr) << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends