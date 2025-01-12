//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxWater(vector<int> &arr) {
        int N = arr.size();
        int tWater = 0;
        //previous max - current height
        // 3-3, 3-0, 3-1, 3-3,   , 
        //min(prevMax, frontMax) - currHeight
        // 3-3, 3-0, 3-1, 3-4(continue), 2-0, 2-2
        
        vector<int> prevMax(N);
        vector<int> frontMax(N);
        
        int m1 = arr[0];
        for(int i = 0; i < N; ++i) {
            m1 = max(m1, arr[i]);
            prevMax[i] = m1;
        }
        
        m1 = arr[N-1];
        for(int i = N-1; i >= 0; --i) {
            m1 = max(m1, arr[i]);
            frontMax[i] = m1;
        }
        
        for(int i = 0; i < N; ++i) {
            int curr = min(prevMax[i], frontMax[i]) - arr[i];
            if(curr < 0) tWater += 0;
            else tWater += curr;
        }
        
        return tWater;
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