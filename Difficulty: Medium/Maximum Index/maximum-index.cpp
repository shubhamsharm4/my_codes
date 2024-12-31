//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxIndexDiff(vector<int>& arr) {
        int N = arr.size();
        
        vector<int> prefix(N);
        vector<int> suffix(N);
        
        int mini = arr[0];
        for(int i = 0; i < N; ++i) {
            mini = min(mini, arr[i]);
            prefix[i] = mini;
        }
        
        int maxi = arr[N-1]; 
        for(int i = N-1; i >= 0; --i) {
            maxi = max(maxi, arr[i]);
            suffix[i] = maxi;
        }
        
        int maxLen = 0;
        int i = 0, j = 0;
        while(j < N) {
            if(prefix[i] <= suffix[j]) {
                maxLen = max(maxLen, j - i);
                j++;
            }
            else i++;
        }
        
        return maxLen;
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
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        auto ans = ob.maxIndexDiff(arr);
        cout << ans << "\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends